#include <stdio.h>

int main(int argc, char *argv[]) 
{
	/*for (int i=0;i<=127;i++) 
	{
		printf("%c的ASCII序号是%d\n", i, i);
	}
	*/
	char nerf ='\n';
	printf("Nerf is  %c.\n", nerf);
	//char可以用于表示一个字符（包括换行符，制表符等），但实质是int。
	printf("\" Hello World  \" \n");//注意“ 和斜线/的输出方法。
	printf("反斜线\\ ");  //斜线可以直接输出，而反斜线需要转义字符。
	printf("斜线/");
	return 0;
}