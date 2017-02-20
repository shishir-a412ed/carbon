// Reverse an array using recursion.
// Time Complexity O(n). Space Complexity O(1) if recursion (stack) space is excluded.

#include <iostream>

using namespace std;

void reverseArray(int*, int&, int);

int main(){
int a[]={10,9,8,7,6,5,4,3,2,1};
int size=sizeof(a)/sizeof(a[0]);
int i=0;
cout<<"Original Array:\n";
for(int i=0;i<size;i++)
   cout<<a[i]<<" ";
reverseArray(a, i, size);
cout<<"\nReverse Array:\n";
for(int i=0;i<size;i++)
   cout<<a[i]<<" ";
cout<<endl;
return 0;
}

void reverseArray(int *a, int &i, int size){
if (i >= size)
   return;
int val=*(a+i);
i++;
reverseArray(a, i, size);
*(a+size-i)=val;
i--;
}

