#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

char buffer[MAXLEN];
char split[MAXLEN];
char *keyword;
char *path;
char *token;
FILE *fp;
const char delim[3] = " \n";

int main(int argc, char **argv)

{
    if(argc < 2){
        printf("Need more args\n");
        return -1;
    }

    keyword = argv[1];
    path = argv[2];
    fp = fopen(path, "r");

    while(fgets(buffer, MAXLEN, fp) != NULL){  // While file has lines
        strcpy(split, buffer);                 // copy the line from buffer into a new array where we can do token splitting
        token = strtok(split, delim);
        while(token != NULL){                  // loop over tokens
            if(strcmp(token, keyword) == 0)    // if token matches keyword we print out the line stored in buffer
                printf("Found: %s", buffer);
            token = strtok(NULL, delim);
        }
    }
}