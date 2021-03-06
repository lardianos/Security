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
	BIGNUM *M = BN_new();
	BIGNUM *M2 = BN_new ();
	BIGNUM *crypto_message = BN_new();	
	BIGNUM *decripted_message = BN_new();
	BIGNUM *signature = BN_new();
	BIGNUM *signature2 = BN_new();
	BIGNUM *signature_rev = BN_new();
	BIGNUM *signature2_rev = BN_new();	
	/*
		Dimosio Klidi (e,n)
		Idiotiko klidi (d,n)
	*/
	BN_hex2bn(&n,"DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_hex2bn(&e,"010001");	
	BN_hex2bn(&d,"74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
	BN_hex2bn(&M, "49206f776520796f75202432303030");
	BN_hex2bn(&M2,"49206f776520796f75202433303030");	

	printBN("n= ",n);
	printBN("e= ",e);
	printBN("d= ",d);
	printBN("crypto message= ",crypto_message);

	BN_mod_exp(signature, M, d, n, ctx);
	BN_mod_exp(signature2, M2, d, n, ctx);
	printBN("sugnature 1 = ",signature);
	printBN("sugnature 2 = ",signature2);

	BN_mod_exp(signature_rev, signature, e, n, ctx);
	BN_mod_exp(signature2_rev, signature2, e, n, ctx);
	printBN("message 1 = ",signature_rev);
	printBN("message 2 = ",signature2_rev);		
	return 0;
}