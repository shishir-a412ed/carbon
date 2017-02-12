/*
Given a stack, sort it using recursion. 
Use of any loop constructs like while, for..etc is not allowed.
We can only use the following ADT functions on Stack S:
	is_empty(S)  : Tests whether stack is empty or not.
	push(S)	     : Adds new element to the stack.
	pop(S)	     : Removes top element from the stack.
	top(S)	     : Returns value of the top element. Note that this
               	       function does not remove element from the stack.
*/

#include <iostream>
#include <stack>

using namespace std;

void sort();
void sortInsert(int);

stack<int> s;

int main(){
char ch='y';
int val;
cout<<"Push the elements on stack\n";
while(ch == 'y' || ch == 'Y'){
cin>>val;
s.push(val);
cout<<"Do you wish to push another element [y/n]\n";
cin>>ch;
}
cout<<"Performing Sort Operation ...\n";
sort();
cout<<"Elements in stack after sort()\n";
while(!s.empty()){
	val = s.top();
	s.pop();
	cout<<val<<" ";
}
cout<<endl;
return 0;
}

void sortInsert(int x){
if (s.empty())
	s.push(x);
else{
	int a = s.top();
	if (a>x){
	   s.pop();
	   sortInsert(x);
	   s.push(a);
	}else{
	   s.push(x);	
	}	
}
}

void sort(){
if (!s.empty()){
	int x=s.top();
	s.pop();
	sort();
	sortInsert(x);
	}
}
