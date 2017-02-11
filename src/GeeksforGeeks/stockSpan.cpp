// http://www.geeksforgeeks.org/the-stock-span-problem/
// Time Complexity: O(n^2)

#include <iostream>

using namespace std;

int calculateStockSpan(int*, int);

int main(){
int a[]={100,80,60,70,60,75,85};
int size=sizeof(a)/sizeof(a[0]);
cout<<"Original Array:\n";
for(int i=0;i<size;i++)
{
cout<<a[i]<<" ";
}
cout<<"\n";
cout<<"Stock Span:\n";
for(int i=0;i<size;i++)
{
cout<<calculateStockSpan(a,i)<<" ";
}
cout<<"\n";
return 0;
}

int calculateStockSpan(int *a, int i){
int stockSpan=1;
for (int j=i-1;j>=0;j--)
{
if (*(a+j)<=*(a+i))
{
stockSpan++;
}else{
break;
}
}
return stockSpan;
}
