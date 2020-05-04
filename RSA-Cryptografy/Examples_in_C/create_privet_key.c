#include <stdio.h> 
#include <openssl/bn.h> 
//Το String να περιέχει έναν ακέραιο σε δεκαδικό σύστημα (dec):
	//BN_dec2bn(&a, “12345678901112231223"); 

	//Το String να περιέχει έναν ακέραιο σε δεκαεξαδικό τιμή (hex):
	//BN_hex2bn(&a, “2A3B4C55FF77889AED3F");

	//Δημιουργία τυχαίου ακέραιου αριθμού (128 bits)
	//BN_rand(a, 128, 0, 0); 

	//Δημιουργία τυχαίου ακέραιου πρώτου αριθμού (128 bits)
	//BN_generate_prime_ex(a, 128, 1, NULL, NULL, NULL); 

	//Υπολογισμός res = a-b: 
	//BN_sub(res, a, b); 

	//Υπολογισμός res = a+b: 
	//BN_add(res, a, b); 

	//Υπολογισμός res = a ∗ b (Απαιτείται μια BN CTX δομή): 
	//BN_mul(res, a, b, ctx) 

	//Υπολογισμός res = a ∗ b mod n: 
	//BN_mod_mul(res, a, b, n, ctx) 

	//Υπολογισμός res = a^c mod n: 
	//BN_mod_exp(res, a, c, n, ctx) 

	

	// δηλαδή, για ένα a να βρεθεί b, τέτοιο ώστε a * b mod n = 1 (a * b ≡ 1 mod n)
	// Η τιμή b καλείται ο αντίστροφος του a, στην αριθμητική υπολοίπου n και υπάρχει μόνο αν gcd(a,b)=1 

	// BN_mod_inverse(b, a, n, ctx);
	/*
		n = p*q
		Dimosio Klidi (e,n)
		Idiotiko klidi (d,n)
		e * d = 1 mod (p - 1) * (q - 1) =>
		e * d mod (p-1)*(q-1) = 1
	*/

	/*
	Βήματα:
		*Υπολογίζουμε p-1
		*Υπολογίζουμε q-1
		*Υπολογίζουμε (p-1)*(q-1)
		*Υπολογίζουμε τον αντίστροφο (mod_inverse) => έχουμε το d
	*/

	/*	
		A top secret! in hex
		4120746f702073656372657421
	*/
void printBN(char *msg, BIGNUM * a) { 
	char * number_str = BN_bn2hex(a); 
	printf("%s %s\n", msg, number_str); 
	OPENSSL_free(number_str); 
} 

int main(int argc, char const *argv[]){
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *p = BN_new();	
	BIGNUM *q = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *n = BN_new();
	BIGNUM *q_minus_1 = BN_new();
	BIGNUM *p_minus_1 = BN_new();
	BIGNUM *n_res = BN_new();
	BIGNUM *d = BN_new();
	BIGNUM *one = BN_new();



	BN_hex2bn(&p,"F7E75FDC469067FFDC4E847C51F452DF");
	BN_hex2bn(&q,"E85CED54AF57E53E092113E62F436F4F");
	BN_hex2bn(&e,"0D88C3");
	BN_hex2bn(&one,"1");

	printBN("p= ",p);
	printBN("q= ",q);
	printBN("e= ",e);
	printBN("one= ",one);

	BN_mul(n, p, q, ctx);

	printBN("n= ",n);

	BN_sub(q_minus_1, q, one);
	BN_sub(p_minus_1, p, one);
	BN_mul(n_res, p_minus_1, q_minus_1, ctx);
	BN_mod_inverse(d, e, n_res, ctx);
	printBN("d= ",d);
	return 0;
}