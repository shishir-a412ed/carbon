// Find unique element in an array, where every element appears twice except one.
// HINT: Bit manipulation.

#include <iostream>

using namespace std;

int getUnique(int [], int);

int main(){
int a[]={12,10,7,6,99,1,6,99,7,12,10};
int size=sizeof(a)/sizeof(a[0]);
cout<<"Original Array is:\n";
for(int i=0;i<size;i++)
   cout<<a[i]<<" ";
cout<<"\nUnique element in the array is: "<<getUnique(a, size)<<endl;
return 0;
}

int getUnique(int a[], int size){
 int result=0;
 for(int i=0;i<size;i++)
   result = result^a[i];
 return result;
}
