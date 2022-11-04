#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <malloc.h>
#include <string.h>
#include <sys/socket.h>
#include <resolv.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#define FAIL    -1

int OpenConnection(const char *hostname, int port)
{
    int sd;
    struct hostent *host;
    struct sockaddr_in addr;
    if ( (host = gethostbyname(hostname)) == NULL )
    {
        perror(hostname);
        abort();
    }
    sd = socket(PF_INET, SOCK_STREAM, 0);
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = *(long*)(host->h_addr);
    if ( connect(sd, (struct sockaddr*)&addr, sizeof(addr)) != 0 )
    {
        close(sd);
        perror(hostname);
        abort();
    }
    return sd;
}
SSL_CTX* InitCTX(void)
{
    SSL_METHOD *method;
    SSL_CTX *ctx;
	/* Load cryptos, et.al. */
	/* Bring in and register error messages */
	/* Create new client-method instance */
	/* Create new context */
    if ( ctx == NULL )
    {
        ERR_print_errors_fp(stderr);
        abort();
    }
    return ctx;
}
void ShowCerts(SSL* ssl)
{
    X509 *cert;
    char *line;
	/* get the server's certificate */
    if ( cert != NULL )
    {
        printf("Server certificates:\n");
        /* */
        printf("Subject: %s\n", line);
       	/* */
        printf("Issuer: %s\n", line);
        free(line);
    }
    else
        printf("Info: No client certificates configured.\n");
}
int main(int count, char *strings[])
{
    SSL_CTX *ctx;
    int server;
    SSL *ssl;
    char buf[1024];
    char acClientRequest[1024] = {0};
    int bytes;
    char *hostname, *portnum;

    if ( count != 3 )
    {
        printf("usage: %s <hostname> <portnum>\n", strings[0]);
        exit(0);
    }
    
    /* create new SSL connection state */
	/* attach the socket descriptor */
	/* perform the connection */
    if ( SSL_connect(ssl) == FAIL )   /* connection fail */
        ERR_print_errors_fp(stderr);
    else
    {
        char acUsername[16] = {0};
        char acPassword[16] = {0};
        const char *cpRequestMessage = "<Body>\
                               <UserName>%s<UserName>\
                 <Password>%s<Password>\
                 <\Body>";
        printf("Enter the User Name : ");
        scanf("%s",acUsername);
        printf("\n\nEnter the Password : ");
        scanf("%s",acPassword);
				/* construct reply */
        printf("\n\nConnected with %s encryption\n", SSL_get_cipher(ssl));
   		/* get any certs */
        /* encrypt & send message */
        /* get reply & decrypt */
	    /* release connection state */
    }
		/* close socket */
		/* release context */
    return 0;
}
