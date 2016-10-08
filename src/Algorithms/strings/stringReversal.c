#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void readString(char *);
char* reverseString(char*);

int main(){
char *str=(char *)malloc(sizeof(char)*100);
char *dest;
readString(str);
dest=reverseString(str);
printf("%s\n",dest);
return 0;
}

char* reverseString(char *src)
{
char *dest=(char *)malloc(sizeof(char)*strlen(src)+1);
int i, j;
for(i=0,j=strlen(src)-1;i<strlen(src),j>=0;i++,j--)
{
*(dest+i)=*(src+j);
}
*(dest+i)='\0';
return dest;
}

void readString(char *str)
{
int i=0;
char ch;
ch=getchar();
while(ch != '\n' && i<99)
{
*(str+i)=ch;
i++;
ch=getchar();
}
*(str+i)='\0';
}
