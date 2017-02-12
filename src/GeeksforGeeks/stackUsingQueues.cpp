// Implement Stack using Queues.
// We are given a Queue data structure that supports standard operations like enqueue() and dequeue(). 
// We need to implement a Stack data structure using only instances of Queue and queue operations
// allowed on the instances.

#include <iostream>
#include <queue>

using namespace std;

class myStack{
private:
    queue<int> q1,q2;
public:
    void push(int);
    void pop();
    int top();
    bool empty();
};

void myStack::push(int val){
int x;
while(!q1.empty()){
     x=q1.front();
     q1.pop();
     q2.push(x);
}
q1.push(val);
while(!q2.empty()){
     x=q2.front();
     q2.pop();
     q1.push(x);
}
}

void myStack::pop(){
   q1.pop();
}

int myStack::top(){
   return q1.front();
}

bool myStack::empty(){
     return q1.empty();
}

int main(){
myStack s;
char ch='y';
int val;
cout<<"Push the elements on stack\n";
while(ch == 'y' || ch == 'Y'){
cin>>val;
s.push(val);
cout<<"Do you wish to push another element [y/n]\n";
cin>>ch;
}
cout<<"Element on the stack are: \n";
while(!s.empty()){
     val=s.top();
     s.pop();
     cout<<val<<" ";
}
cout<<endl;
return 0;
}


