// Implement Queue using two Stacks.

#include <iostream>
#include <stack>

using namespace std;

class myQueue{
	stack<int> s1,s2;
public:
	void push(int);
	int front();
	void pop();
	bool empty();
};

void myQueue::push(int val){
int x;
while(!s1.empty()){
	x=s1.top();
	s1.pop();
	s2.push(x);
}
s1.push(val);
while(!s2.empty()){
	x=s2.top();
	s2.pop();
	s1.push(x);
}
}

int myQueue::front(){
	return s1.top();
}

void myQueue::pop(){
	s1.pop();
}

bool myQueue::empty(){
	return s1.empty();
}

int main(){
myQueue q;
char ch='y';
int val;
cout<<"Insert the elements in the queue\n";
while(ch == 'y' || ch == 'Y'){
cin>>val;
q.push(val);
cout<<"Do you wish to push another element [y/n]\n";
cin>>ch;
}
cout<<"Elements in the queue are:\n";
while(!q.empty()){
	val=q.front();
	q.pop();
	cout<<val<<" ";
}
cout<<endl;
return 0;
}
	
