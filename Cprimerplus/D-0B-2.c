// copy a file
// argv[1]: raw      argv[2] destination

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 256

void copy_bin(FILE * raw, FILE * dest);
void copy_txt(FILE * raw, FILE * dest);

int main(int argc, char *argv[]) 
{
	
	if (argc < 3)
	{
		fprintf(stderr, "Usage ./a.out [raw] [copy]\n");
		fprintf(stderr, "Not enough arguments, expected 3, but %d.\n", argc);
		return 1;
	}
	FILE * fp_raw = fopen(argv[1], "rb"), * fp_dest = fopen(argv[2], "wb");
	if (fp_raw == NULL)
	{
		fprintf(stderr, "Fail in opening raw file %s.\n", argv[1]);
		return 2;
	}
	if (fp_dest == NULL)
	{
		fprintf(stderr, "Fail in opening destination file.\n");
		return 3;
	}
	
	fprintf(stdout, "Choose the model:\nA.binary \t	B.text\n");
	char ch ;
	if ((ch = toupper(getchar())) != 'A' && ch != 'B')
		return 4;
	
	else if (ch == 'A')
	{
		fprintf(stdout, "copying(binary model) ...\n");
		copy_bin(fp_raw, fp_dest);
	}
	else 
	{
		fprintf(stdout, "copying(text model) ...\n");
		copy_txt(fp_raw, fp_dest);
	}
	if (fclose(fp_raw))
	{
		fprintf(stderr, "Error in closing raw file:%s\n", argv[1]);
		return 5;
	}
	if (fclose(fp_dest))
	{
		fprintf(stderr, "Error in closing destination file:%s\n", argv[1]);
		return 6;
	}
	fprintf(stdout,"Successfully copy the file.\n");
	
	return 0;
	
}


void copy_bin(FILE * raw, FILE * dest)
{
	char temp[1];
	while ((fread(temp, sizeof(char), 1, raw)) )
		temp[0] = toupper(temp[0]);
		fwrite(temp, sizeof(temp), 1, dest);
}


void copy_txt(FILE * raw, FILE * dest)
{
	char ch;
	while( (ch = toupper(fgetc(raw))) != EOF )
		fputc(ch, dest);
}