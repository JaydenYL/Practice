#include <stdio.h>

void reverse(int array[], unsigned int length) 
{
	scanf("%u", length);
	
	// TODO
}


int main() {
	unsigned int length ;
	scanf("%u", &length);
	int array[length];
	int temp = -1;
	for(int i = 0; i < length; i++) 
	{
		scanf("%d", &temp);
		array[i] = temp;
	}
	reverse(array, length);
	for(int i = length - 1; i >= 0; i--) 
	{
		printf("%d\n", array[i]);
	}
	return 0;
}
