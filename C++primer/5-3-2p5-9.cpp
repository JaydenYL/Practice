#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int counter = 0 ;
	string str;
	getline(cin, str);
	for (int i = 0; i <= str.length(); ++i) {
		switch (str[i]) {
			case 'a':case 'e': case 'i': case 'o': case 'u':
				counter ++;
				break;
			default:
				break;
		}
	}



/*******************************************************************
 *  The code below doesnot work, because once the case is matched, 
 *	it will execute the all the cases from the matched one. 
 *	And the keyword continue cannot be used in swith statement
 */

	
//	int i = 0;
//	switch (str[i]) {
//		case 'a':case 'e': case 'i': case 'o': case 'u':
//			++counter;
//			++i;
//
//		case '\0':
//			cout << "i = " << i << endl;
//			cout << str[i] << endl;
//			break;
//		default:
//			cout << "i = " << i << endl;
//			++i;
//	}
	
	cout << counter << endl;
	
	return 0;
}