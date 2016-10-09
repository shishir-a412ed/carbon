/*
 This program reads a string from STDIN (user), and reverse the words in the string.
 e.g. "hello world" will output "olleh dlrow"
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

class Stack{
   int top;
   char *a;
   int size;	
public:
   Stack(int t, int s){
	top=t;
	a=(char *)malloc(sizeof(char)*s);
        size=s;
   }
   ~Stack(){
     free(a);
   }
   char topElement();
   void push(char);
   char pop();
   bool isEmpty();
};

bool Stack::isEmpty()
{
if (top==-1)
   return true;
else
   return false;
}

char Stack::topElement()
{
if (top>=0)
   return *(a+top);
return -1;
}

void Stack::push(char item)
{
if (top<size-1)
{
top++;
*(a+top)=item;
}else{
cout<<"Stack overflow\n";
exit(1);
}
}

char Stack::pop()
{
if (top>=0)
{
return *(a+(top--));
}
return -1;
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

int main()
{
char *str=(char *)malloc(sizeof(char)*100);
readString(str);
Stack s(-1,strlen(str));
while (*str)
{
if (*str != ' ')
{
s.push(*str);
str++;
}
else{
while(!s.isEmpty())
{
char ch=s.pop();
cout<<ch;
}
cout<<" ";
str++;
}
}
while(!s.isEmpty())
{
char ch=s.pop();
cout<<ch;
}
cout<<endl;
return 0;
}
