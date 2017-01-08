// Time Complexity O(n).

#include <iostream>
#include <utility>

using namespace std;

pair<int,int> findPairWithTargetSum(int*, int, int);

int main(){
int sum;
int a[]={1,2,3,9};
cout<<"Original Array:\n";
int size=sizeof(a)/sizeof(a[0]);
for (int i=0;i<size;i++)
    cout<<a[i]<<" ";
cout<<"\nEnter target Sum\n";
cin>>sum;
pair<int,int> p=findPairWithTargetSum(a,size,sum);
cout<<p.first<<" "<<p.second<<"\n";
return 0;
}

pair<int,int> findPairWithTargetSum(int *a, int size, int sum)
{
int low=0;
int high=size-1;
pair<int,int> p(-1,-1);
while(low<high)
{
if(*(a+low) + *(a+high) == sum)
{
p=make_pair(*(a+low),*(a+high));
break;
}else if (*(a+low) + *(a+high) < sum)
{
low=low+1;
}else{
high=high-1;
}
}
return p;
}
