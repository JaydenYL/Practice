// Author: LIU YU
// 2019-9-20 20:22 AEST

#include <stdio.h>
#include <string.h>

int main()
{
	char line[100], anag[100], line_str[100], anag_str[100];
	memset(line, 0, 100);
	memset(line_str, 0, 100);
	memset(anag, 0, 100);
	memset(anag_str, 0, 100);
	
	printf("Enter line: ");
	scanf("%[^\n]", line);
	getchar();
	printf("Enter anagram: ");
	scanf("%[^\n]", anag);
	
	unsigned int len_line = strlen(line);
	unsigned int len_anag = strlen(anag);
	int j = 0;
	
	for(int i = 0 ;i < len_line; i ++)
	{
		if ((( line[i] <='Z') && (line[i] >= 'A')) || ((line[i] <= 'z') && (line[i] >= 'a')))
		{	
			if (( line[i] <='Z') && (line[i] >= 'A'))
			{
				line[i] += 32;
			}
			line_str[j] = line[i];
			j ++;
		}
	}

	j = 0;
	for(int i = 0;i < len_anag; i ++)
	{
		if ((( anag[i] <='Z') && (anag[i] >= 'A')) || ((anag[i] <= 'z') && (anag[i] >= 'a')))
		{
			if (( anag[i] <='Z') && (anag[i] >= 'A'))
			{
				anag[i] += 32 ;
			}
			anag_str[j] = anag[i];
			j ++;
		}
	}

	len_anag = strlen(anag_str);
	len_line = strlen(line_str);
	for(int i = 0; i < len_anag; i++)
	{
		for(int j = 0; j < len_line; j++)
		{
			if (line_str[j] == anag_str[i])
			{
				line_str[j] = '0';
				anag_str[i] = '0';
				break;
			}
		}
	}
	
	if(strcmp(anag_str, line_str) == 0) printf("\nAnagram!\n");
	else printf("\nNot an anagram.\n");
	return 0;
}