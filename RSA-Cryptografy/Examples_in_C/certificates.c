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
	BN_hex2bn(&n,"9CD30CF05AE52E47B7725D3783B3686330EAD735261925E1BDBE35F170922FB7B84B4105ABA99E350858ECB12AC468870BA3E375E4E6F3A76271BA7981601FD7919A9FF3D0786771C8690E9591CFFEE699E9603C48CC7ECA4D7712249D471B5AEBB9EC1E37001C9CAC7BA705EACE4AEBBD41E53698B9CBFD6D3C9668DF232A42900C867467C87FA59AB8526114133F65E98287CBDBFA0E56F68689F3853F9786AFB0DC1AEF6B0D95167DC42BA065B299043675806BAC4AF31B9049782FA2964F2A20252904C674C0D031CD8F31389516BAA833B843F1B11FC3307FA27931133D2D36F8E3FCF2336AB93931C5AFC48D0D1D641633AAFA8429B6D40BC0D87DC393");
	printf("\n");
	BN_hex2bn(&e,"010001");
	printf("\n");
	BN_hex2bn(&signature,"dd33d711f3635838dd1815fb0955be7656b97048a56947277bc2240892f15a1f4a1229372474511c6268b8cd957067e5f7a4bc4e2851cd9be8ae879dead8ba5aa1019adcf0dd6a1d6ad83e57239ea61e04629affd705cab71f3fc00a48bc94b0b66562e0c154e5a32aad20c4e9e6bbdcc8f6b5c332a398cc77a8e67965072bcb28fe3a165281ce520c2e5f83e8d50633fb776cce40ea329e1f925c41c1746c5b5d0a5f33cc4d9fac38f02f7b2c629dd9a3916f251b2f90b119463df67e1ba67a87b9a37a6d18fa25a5918715e0f2162f58b0062f2c6826c64b98cdda9f0cf97f90ed434a12444e6f737a28eaa4aa6e7b4c7d87dde0c90244a787afc3345bb442");
	printf("\n");
	BN_hex2bn(&hash, "d00693db9280d33b530b9ef3c71ea31f03a2296ba31f74d1f015d0e0bf5eb731");
	printf("\n");
	printBN("n= ",n);
	printBN("e= ",e);
	printBN("sugnature= ",signature);
	printBN("hash      = ",hash);
		
	BN_mod_exp(signature_rev, signature, e, n, ctx);
	BN_mask_bits(signature_rev,256);
	printBN("sugnature = ",signature_rev);
	printf("\n");


	return 0;
}