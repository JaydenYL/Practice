/*
 * Extension of 5-3-2p5-09.c
 * Besides the lower bound vowel letters, it should also be able to 
 * detect the upper bound.
*/

#include <iostream>
#include <ctype.h>

using namespace std;
int main(int argc, char *argv[]) {
    int counter = 0 ;
    string str;
    getline(cin, str);
    for (int i = 0; i <= str.length(); ++i) {
        switch (tolower(str[i])) {
            case 'a':case 'e': case 'i': case 'o': case 'u':
                counter ++;
                break;
            default:
                break;
        }
    }
    
    return 0;
}