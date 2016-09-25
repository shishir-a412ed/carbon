/*
Implement binary search using recursion.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

void populateArray(int*,int);
bool binarySearch(int*,int,int, int);

int main()
{
int a[10],size,i;
int low, high, val;
size=sizeof(a)/sizeof(int);
populateArray(a, size);
low=0;
high=size-1;
cout<<"Enter the number to be searched\n";
cin>>val;
bool isFound = binarySearch(a,low,high,val);
if (isFound)
	cout<<"Number exists\n";
else
	cout<<"Number does not exist\n";
return 0;
}

bool binarySearch(int *a, int low, int high, int val)
{
if (low<=high)
{
int mid=low+(high-low)/2;
if (*(a+mid)==val)
	return true;
else if(*(a+mid)<val)
	return binarySearch(a, mid+1, high, val);
else
	return binarySearch(a, low, mid-1, val);
}
return false;
}
void populateArray(int *a, int size)
{
int i, val=0;
cout<<"Enter the elements of the array in sorted order\n";
for(i=0;i<size;i++)
{
cin>>val;
if (i>0 && *(a+(i-1)) > val)
{
cout<<"You cannot enter an element smaller than the previous element. Exiting ...\n";
exit(0);
}
*(a+i)=val;
}
}


