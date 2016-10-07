#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strcopy(char *, char *);

int main()
{
char *src="hello world\0";
char *dest=(char *)malloc(sizeof(char)*12);
strcopy(dest, src);
printf("%s\n", dest);
free(dest);
return 0;
}

void strcopy(char *dest, char *src)
{
int i;
for(i=0;i<strlen(src)+1;i++)
{
*(dest+i)=*(src+i);
}
}
