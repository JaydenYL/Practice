#include <stdio.h>



char get_char(FILE* fp, long pos);
int comparator(FILE* fp, long str_pos_1, long str_pos_2, int asc);



int main(int argc, char *argv[]) {
	
	FILE* fp = fopen("words.list", "r");
	long pt1 = 0, pt2 = 6;
	int res = comparator(fp, pt1, pt2, 1);
	printf("res : %d\n", res);
	return 0;
	
}


char get_char(FILE* fp, long pos){
	fseek(fp, pos, SEEK_SET);
	return fgetc(fp);
}


int comparator(FILE* fp, long str_pos_1, long str_pos_2, int asc) {
	int ret = 0;
	char ch_1, ch_2;
	while (!(ret = (ch_1 = get_char(fp, str_pos_1)) - (ch_2 = get_char(fp, str_pos_2))) 
		// && ch_1 && ch_1 != 10 && ch_1 != EOF
		&& ch_2 && ch_2 != 10 && ch_2 != EOF
	) {
		++str_pos_1, ++str_pos_2;
	}
	if (ret == 0) return 0;
	return (ret > 0) ? -asc : asc;
}