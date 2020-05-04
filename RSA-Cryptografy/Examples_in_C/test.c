#include <stdio.h> 
#include <openssl/bn.h> 

#define NBITS 256 

void printBN(char *msg, BIGNUM * a) 
{ 
/* Use BN_bn2hex(a) for hex string 
 * Use BN_bn2dec(a) for decimal string */ 
char * number_str = BN_bn2hex(a); 
printf("%s %s\n", msg, number_str); 
OPENSSL_free(number_str); 
} 

int main () 
{ 
	BN_CTX *ctx = BN_CTX_new(); //ctx structure
	BIGNUM *a = BN_new();  // random prime
	BIGNUM *b = BN_new();  // string decimal
	BIGNUM *n = BN_new();  // random integer
	BIGNUM *res = BN_new();  // integer to hold results

	// Initialize a, b, n 

	BN_generate_prime_ex(a, NBITS, 1, NULL, NULL, NULL); 	

	BN_dec2bn(&b, "273489463796838501848592769467194369268"); 
	
	BN_rand(n, NBITS, 0, 0); 
	// calculate res = a*b 
	BN_mul(res, a, b, ctx); 

	// print result
	printBN("a * b = ", res); 


	// calculate res = aˆb mod n 
	BN_mod_exp(res, a, b, n, ctx); 

	// print result
	printBN("aˆc mod n = ", res); 
	return 0; 
}