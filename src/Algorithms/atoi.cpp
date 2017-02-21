#include <iostream>
#include <cstdio>

using namespace std;

void readString(char *);

int main(){
char s[100];
cout<<"Enter an input string (atoi):\n";
readString(s);
int result=0,i=0,sign=1;
// Handle negative integers.
if (s[i]=='-'){
   sign=-1;
   i++;
}
while(s[i]!='\0'){
   result=result*10+s[i]-'0';
   i++;
}
cout<<"Atoi of string is: "<<sign*result<<endl;
return 0;
}

void readString(char *str){
char ch;
int i=0;
ch=getchar();
while(ch != '\n'){
   *(str+i)=ch;
   i++;
   ch=getchar();
}
*(str+i)='\0';
}
