// Reverse a stack by using only push() and pop() operations
// without using any secondary data structures.

#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

void reverse();
void bottomInsert(int);

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
reverse();
cout<<"Reverse Stack (LIFO)\n";
while(!s.empty())
{
	int element=s.top();
	s.pop();
	cout<<element<<" ";
}
cout<<endl;
return 0;
}

void bottomInsert(int x){
if (s.empty())
	s.push(x);
else{
	int a=s.top();
	s.pop();
	bottomInsert(x);
	s.push(a);
    }
}

void reverse(){
if (!s.empty()){
	int x=s.top();
	s.pop();
	reverse();
	bottomInsert(x);
	}
}


