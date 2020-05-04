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
	BIGNUM *d = BN_new();
	BIGNUM *crypto_message = BN_new();
	BIGNUM *decripted_message = BN_new();
	/*
		Dimosio Klidi (e,n)
		Idiotiko klidi (d,n)
	*/
	BN_hex2bn(&n,"DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_hex2bn(&e,"010001");
	BN_hex2bn(&d,"74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");	
	BN_hex2bn(&crypto_message,"8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");

	printBN("n= ",n);
	printBN("e= ",e);
	printBN("d= ",d);
	printBN("crypto message= ",crypto_message);

	BN_mod_exp(decripted_message, crypto_message, d, n, ctx);
	printBN("decripted message = ",decripted_message);	

	return 0;
}