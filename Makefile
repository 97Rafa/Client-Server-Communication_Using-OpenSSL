default: client server

client:
	gcc -Wall -o client client.c -L/usr/lib -lssl -lcrypto

server:
	gcc -Wall -o server server.c -L/usr/lib -lssl -lcrypto

clean:
	rm client server


distclean:
	rm client server mycert.pem
