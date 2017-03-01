// Given a sequential array starting from 0 to N. e.g. 0,1,2,3,4,5,5,6,7,8,9,10.
// There is a duplicate element in the array. Output that duplicate element.

#include <iostream>

using namespace std;

// Time Complexity O(n). Space Complexity O(1).
int findDuplicate1(int a[], int size){
int prev=a[0];
int curr;
for(int i=1;i<size;i++)
{
curr=a[i];
if (curr==prev)
   return curr;
prev=curr;
}
return -1;
}



int main(){
int a[]={0,1,2,3,4,5,5,6,7,8,9,10};
int size=sizeof(a)/sizeof(a[0]);
cout<<"Original Array is:\n";
for(int i=0;i<size;i++)
   cout<<a[i]<<" ";
int result=findDuplicate1(a, size);
cout<<"\nDuplicate element is: "<<result<<endl;
return 0;
}
