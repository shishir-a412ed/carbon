/*
Binary search implementation in C++.
Time Complexity: O(log n)
*/

#include <iostream>

using namespace std;

void populateList(int *);
bool bSearch(int *, int, int);

int main()
{
int a[10], i, val, arraySize;
populateList(a);
arraySize = sizeof(a)/sizeof(int);
cout<<"Enter the value to be searched\n";
cin>>val;
bool result=bSearch(a, val, arraySize);
if (result)
{
cout<<"Number exists\n";
}
else
{
cout<<"Number does not exist\n";
}
return 0;
}

bool bSearch(int *a, int val, int size)
{
int low=0, high=size-1;
int mid;
while (low <= high)
{
	mid = (low+high)/2;
	if(*(a+mid)==val)
	{
	return true;
	}
	else if(*(a+mid)<val)
	{
	low=mid+1;
	}
	else
	{
	high=mid-1;
	}
}
return false;
}

void populateList(int *a)
{
int i, val;
cout<<"Enter the elements of the list (1-10) in sorter order\n";
for(i=0;i<10;i++)
{
cout<<"Enter element "<<i+1<<endl;
cin>>val;
*(a+i)=val;
}
}
