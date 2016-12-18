// http://www.geeksforgeeks.org/count-pairs-array-hold-iarri-jarrj/
#include <iostream>

using namespace std;

int countPairs(int[], int);

int main()
{
int arr[] = {5, 0, 10, 2, 4, 1, 6};
int count=countPairs(arr, sizeof(arr)/sizeof(arr[0]));
cout<<"Count: "<<count<<endl;
return 0;
}

int countPairs(int a[], int size)
{
int count=0;
int i,j;
for (i=0; i<size; i++)
{
 for (j=i+1;j<size;j++)
    {
    if (i*a[i] > j*a[j])
       count++;
    }
}
return count;
}

