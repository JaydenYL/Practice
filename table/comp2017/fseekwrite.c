#include <stdio.h>

int main ()
{
   FILE *fp;

   fp = fopen("fseekinput.txt","a+");
   fputs("This is seeeeeecond line\n", fp);
  
   fseek( fp, 0, 0 );
   fputs("111st line: C Programming Langauge\n", fp);
   fclose(fp);
   
   return(0);
}