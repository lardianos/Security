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
	BIGNUM *signature = BN_new();
	BIGNUM *hash = BN_new();
	BIGNUM *S_corrupted = BN_new();
	BIGNUM *signature_rev = BN_new();
	/*
		Dimosio Klidi (e,n)
		Idiotiko klidi (d,n)
	*/
	BN_hex2bn(&n,"DCAE58904DC1C4301590355B6E3C8215F52C5CBDE3DBFF7143FA642580D4EE18A24DF066D00A736E1198361764AF379DFDFA4184AFC7AF8CFE1A734DCF339790A2968753832BB9A675482D1D56377BDA31321AD7ACAB06F4AA5D4BB74746DD2A93C3902E798080EF13046A143BB59B92BEC207654EFCDAFCFF7AAEDC5C7E55310CE83907A4D7BE2FD30B6AD2B1DF5FFE5774533B3580DDAE8E4498B39F0ED3DAE0D7F46B29AB44A74B58846D924B81C3DA738B129748900445751ADD37319792E8CD540D3BE4C13F395E2EB8F35C7E108E8641008D456647B0A165CEA0AA29094EF397EBE82EAB0F72A7300EFAC7F4FD1477C3A45B2857C2B3F982FDB745589B");
	printf("\n");
	BN_hex2bn(&e,"010001");
	printf("\n");
	BN_hex2bn(&signature,"737085ef4041a76a43d5789c7b5548e6bc6b9986bafb0d038b78fe11f029a00ccd69140bc60478b2cef087d5019dc4597a71fef06e9ec1a0b0912d1fea3d55c533050ccdc13518b06a68664cbf5621da5bd948b98c3521915ddc75d77a462c2227a66fd33a17ebbebd13c5122673c05da335896afb27d4ddaa74742e37e5013ba6d030b083d0a1c4752185b2e5fa670030a2bc53834dbfd6a883bbbcd6ed1cb31ef1580382008e9cef90f21a5fa2a306da5dbe9fda5da6e62fde588018d3f1627ba6a39faea86972638165ae8283a3b5978a9b2051ff1a3f61401e48d06b38f9e1fa17d8774a88e63d36244fef0ab99f70f38327f8cf2a057510a18a0a8088cd");
	printf("\n");
	BN_hex2bn(&hash, "2c2a46bf245dab54ddb47298621e9629309f0e2c90c4d80d535c7d4e8ab07d29");
	printf("\n");
	printBN("Public Key = ",n);
	printBN("Exponent= ",e);
	printBN("Signature 	= ",signature);
	printBN("Hash     		= ",hash);
		
	BN_mod_exp(signature_rev, signature, e, n, ctx);
	BN_mask_bits(signature_rev,256);
	printBN("Signature auhendicated 	= ",signature_rev);
	printf("\n");


	return 0;
}