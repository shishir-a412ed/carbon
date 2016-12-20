// Insertion Sort. Time Complexity O(n^2).
#include <iostream>

using namespace std;

void insSort(int *,int);

int main(){
int a[]={8,4,3,50,45,22,10,8,1,99,100,3};
int size=sizeof(a)/sizeof(a[0]);
insSort(a, size);
int i;
for(i=0;i<size;i++)
   cout<<a[i]<<endl;
return 0;
}

void insSort(int* a, int n)
{
int i,j,key;
for (j=1;j<n;j++)
{
key=*(a+j);
i=j-1;
while(*(a+i)>key && i>=0)
{
*(a+i+1)=*(a+i);
i=i-1;
}
*(a+i+1)=key;
}
}
