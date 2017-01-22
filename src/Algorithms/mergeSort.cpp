// Merge Sort.
// Time Complexity O(nlogn)

#include <iostream>

using namespace std;

void mergeSort(int [],int,int);
void merge(int [],int,int,int);

int main(){
int a[]={6,5,3,1,8,7,2,6,4};
int size=sizeof(a)/sizeof(a[0]);
cout<<"Original Array:\n";
for(int i=0;i<size;i++)
   cout<<a[i]<<" ";
mergeSort(a, 0, size-1);
cout<<"\nSorted Array:\n";
for(int i=0;i<size;i++)
   cout<<a[i]<<" ";
cout<<"\n";
return 0;
}

void merge(int a[], int l, int m, int r){
int n1=m-l+1;
int n2=r-m;

int L[n1], R[n2];
int i,j,k;
for(i=0;i<n1;i++)
   L[i]=a[l+i];
for(j=0;j<n2;j++)
   R[j]=a[m+1+j];

i=0;
j=0;
k=l;
while(i<n1 && j<n2){
   if (L[i] <= R[j]){
    a[k]=L[i];
    i++;
   }else{
    a[k]=R[j];
    j++;
  }
  k++;
}

while(i<n1){
a[k]=L[i];
k++;
i++;
}

while(j<n2){
a[k]=R[j];
k++;
j++;
}
}

void mergeSort(int a[], int l, int r)
{
if (l<r){
int m=l+(r-l)/2;
mergeSort(a, l, m);
mergeSort(a, m+1, r);
merge(a, l, m, r);
}
}
