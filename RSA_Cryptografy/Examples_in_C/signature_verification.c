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

	//Υπολογισμός res = ac mod n: 
	//BN_mod_exp(res, a, c, n, ctx) 

	// δηλαδή, για ένα a να βρεθεί b, τέτοιο ώστε a * b mod n = 1 (a * b ≡ 1 mod n)
	// Η τιμή b καλείται ο αντίστροφος του a, στην αριθμητική υπολοίπου n και υπάρχει μόνο αν gcd(a,b)=1 

	// BN_mod_inverse(b, a, n, ctx);

void printBN(char *msg, BIGNUM * a) { 
	/* Use BN_bn2hex(a) for hex string 
	 * Use BN_bn2dec(a) for decimal string */ 
	char * number_str = BN_bn2hex(a); 
	printf("%s %s\n", msg, number_str); 
	OPENSSL_free(number_str); 
} 

int main(int argc, char const *argv[]){
	BN_CTX *ctx = BN_CTX_new();
	BIGNUM *e = BN_new();
	BIGNUM *n = BN_new();
	BIGNUM *S = BN_new();
	BIGNUM *M = BN_new();
	BIGNUM *S_corrupted = BN_new();
	BIGNUM *signature_rev = BN_new();
	BIGNUM *signature_rev_corrupted = BN_new();
	/*
		Dimosio Klidi (e,n)
		Idiotiko klidi (d,n)
	*/
	BN_hex2bn(&n,"AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
	BN_hex2bn(&e,"010001");
	BN_hex2bn(&S,"643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");
	BN_hex2bn(&S_corrupted,"643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6803F");
	BN_hex2bn(&M, "4c61756e63682061206d697373696c652e");

	printBN("n= ",n);
	printBN("e= ",e);
	printBN("S= ",S);
	printBN("message     	= ",M);

	BN_mod_exp(signature_rev, S, e, n, ctx);
	printBN("sugnature_rev 	= ",signature_rev);

	BN_mod_exp(signature_rev_corrupted, S_corrupted, e, n, ctx);
	printBN("sugnature 1 = ",signature_rev_corrupted);


	return 0;
}