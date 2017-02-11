// http://www.geeksforgeeks.org/the-stock-span-problem
// Time Complexity O(n)
// Space Complexity O(n)

#include <iostream>
#include <stack>

using namespace std;

void calculateStockSpan(int*, int, int*);

int main(){
int a[]={100,80,60,70,60,75,85};
int size=sizeof(a)/sizeof(a[0]);
cout<<"Original Array:\n";
for(int i=0;i<size;i++)
 cout<<a[i]<<" ";
int *s=new int[size];
cout<<"\nStock Span:\n";
calculateStockSpan(a,size,s);
for(int i=0;i<size;i++)
  cout<<s[i]<<" ";
cout<<"\n";
delete(s);
return 0;
}

void calculateStockSpan(int *a, int size, int *s){
int i=0;
stack<int> st;
st.push(i);
*(s+i)=1;
for(i=1;i<size;i++)
{
while(!st.empty() && *(a+st.top()) <= *(a+i))
     st.pop();
*(s+i) = st.empty()?i+1:i-st.top();
st.push(i);
}
}

