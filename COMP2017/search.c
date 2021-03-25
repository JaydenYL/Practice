#include <stdio.h>
#include <string.h>

#define BUF 400



int search(char *, char *);

int main(int argc, char **argv){
    
    char line[BUF] = {0};
    while (fgets(line, BUF, stdin)) {
        if (search(line, argv[1])) {
            printf("Found: %s", line);
        }
    }
    
    return 0;
}



int search(char *sentence, char *word){
    
    for (int i = 0; i <= strlen(sentence) - strlen(word); i ++) {
        for (int j = 0; j < strlen(word); j ++){
            if (sentence[i + j] != word[j]) {
                break;
            } else if (j == strlen(word) - 1){
                return 1;
            }
        }
    }
    
    return 0;
}