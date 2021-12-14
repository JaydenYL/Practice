#include <iostream>
#include <exception>

using namespace std;
int main(int argc, char *argv[]) {
	
	int a, b ;
label1:
	try {
		cin >> a >> b;
		if (b == 0) {
			throw runtime_error("Invalid denominator!\n");
		}
	} catch (runtime_error err) {
		printf("Invalid denominator!\n:");
		goto label1;
	}
	
	
	
	cout << a/b << endl;
}