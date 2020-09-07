// MacOS uses small endian 

#include <stdio.h>
#include <arpa/inet.h>

int main(void)
{
	unsigned int x = 0x12345678;
	unsigned char *p = (unsigned char *) &x;
	printf("%x,%x,%x,%x\n", p[0], p[1], p[2], p[3]);

	unsigned int y = htonl(x);
	p = (unsigned char *)&y;
	printf("%x,%x,%x,%x\n", p[0], p[1], p[2], p[3]);
	return 0;
}

//作者：Limbo
//链接：https://www.zhihu.com/question/19953760/answer/67879987
//来源：知乎
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。