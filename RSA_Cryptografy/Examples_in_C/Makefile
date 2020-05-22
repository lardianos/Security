privet:
	gcc -o create_privet_key create_privet_key.c -lcrypto
	./create_privet_key
crypto:
	python -c 'print("A top secret!".encode("hex"))'
	gcc -o crypto_messege crypto_messege.c -lcrypto
	./crypto_messege
	python -c 'print("4120746F702073656372657421".decode("hex"))'
decryption:
	gcc -o decrypt decrypt.c -lcrypto
	./decrypt
	python -c 'print("50617373776F72642069732064656573".decode("hex"))'
signatures:
	python -c 'print("M = I owe you $2000.".encode("hex"))'
	python -c 'print("M = I owe you $3000.".encode("hex"))'
	gcc -o signature signature.c -lcrypto
	./signature
	python -c 'print("50617373776F72642069732064656573".decode("hex"))'
verification:
	python -c 'print("Launch a missle.".encode("hex"))'
	gcc -o signature_verification signature_verification.c -lcrypto
	./signature_verification
certifications:
	gcc -o certificates2 certificates2.c -lcrypto
	./certificates2
