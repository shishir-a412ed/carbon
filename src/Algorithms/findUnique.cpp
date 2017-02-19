// Find the element that appears once.
// Time Complexity O(nlogn)

#include <iostream>

using namespace std;

void mergeSort(int [],int,int);
void merge(int [],int,int,int);

int main(){
int a[]={12,12,2,3,2,12,1,2,3,3};
int size=sizeof(a)/sizeof(int);
mergeSort(a,0,size-1);
cout<<"Sorted Array\n";
for(int i=0;i<size;i++)
    cout<<a[i]<<" ";
cout<<endl;
int prev=a[0];
int count=1;
for(int i=1;i<size;i++){
if (a[i] != prev && count %3 != 0)
   break;
prev=a[i];
count++;
}
cout<<"Unique element\n";
cout<<prev<<endl;
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
    i++;
    k++;
}
while(j<n2){
   a[k]=R[j];
   j++;
   k++;
}
}

void mergeSort(int a[], int l, int r){
if (l<r){
int m=l+(r-l)/2;
mergeSort(a, l, m);
mergeSort(a, m+1, r);
merge(a, l, m, r);
}
}
