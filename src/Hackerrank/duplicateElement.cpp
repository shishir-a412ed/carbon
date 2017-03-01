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

// Extension to solution 1. Can you do it O(log n).
// HINT: Binary Search.
// Time Complexity O(log n). Space Complexity O(1).
int findDuplicate2(int a[], int size){
int low=0;
int high=size-1;
int mid=0;
while(low < high){
	mid=low+(high-low)/2;
	if (mid == a[mid]){
		if (mid+1 == a[mid+1]+1)
			break;
		low=mid;
	}else if (mid > a[mid]){
		if (mid-1 == a[mid-1])
			break;
		high=mid;
	}
}
return a[mid];
}

int main(){
int a[]={0,1,2,3,4,5,5,6,7,8,9,10};
int size=sizeof(a)/sizeof(a[0]);
cout<<"Original Array is:\n";
for(int i=0;i<size;i++)
   cout<<a[i]<<" ";
int result=findDuplicate2(a, size);
cout<<"\nDuplicate element is: "<<result<<endl;
return 0;
}
