# Client-Server-Communication_Using-OpenSSL

In this assignment we will create a secure connection between client and server using
the TLS1.2 protocol. In this communication, the client sends an XML request to the
server which contains the username and password. The server verifies the XML
request, if it is valid then it sends a proper XML response to the client or gives a
message of Invalid Request.

Steps of Executing it:

1) First you have to generate your own certificate by typing the command below:
	- openssl req -x509 -nodes -days 365 -newkey rsa:1024 -keyout mycert.pem -out mycert.pem

2) Then you have to compile the C files. I have prepared a Makefile to do this for you.
So you can run "make server" for compiling the server.c file or "make client" for compiling
the client.c file. Or you can do both by simply run "make".

3) After you are done or you have edited the code and you want to delete the old executables
just run "make clean". If you want to delete your generated certificate too run "make distclean".



Compiler used for building this project:
gcc (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0
