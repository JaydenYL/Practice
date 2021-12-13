#include <iostream>
#include <ctype.h>

using namespace std;
int main(int argc, char *argv[]) {
    int counter = 0 ;
    int ffCnt = 0;
    int fiCnt = 0;
    int flCnt = 0;
    string str;
    getline(cin, str);
    for (int i = 0; i <= str.length(); ++i) {
        switch (tolower(str[i])) {
            case 'a':case 'e': case 'i': case 'o': case 'u':
                counter ++;
                break;
            case 'f':
                switch (str[i+1]) {
                    case 'f':
                        ++ffCnt;
                        break;
                    case 'i':
                        ++fiCnt;
                        break;
                    case 'l':
                        ++flCnt;
                        break;
                }
            default:
                break;
        }
    }
    
    cout << "vowel characters :" << counter << endl;
    cout << "ff : " << ffCnt << '\n'
         << "fi : " << fiCnt << '\n'
         << "fl : " << flCnt << endl;
    
    return 0;
}