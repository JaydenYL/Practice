#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main()
{
        struct hostent *host;
        struct in_addr h_addr;

        if ((host = gethostbyname("www.google.com")) != NULL) {
                h_addr.s_addr = *((unsigned long *) host->h_addr);
                printf("%s\n", inet_ntoa(h_addr));
        }
        return 0;
        

}