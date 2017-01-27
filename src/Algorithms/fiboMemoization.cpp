// Calculate fibonacci number using DP Memoization.

#include <iostream>

using namespace std;

int fibo(int);

int main(){
int n;
cout<<"Enter the value of n\n";
cin>>n;
cout<<"Fibonacci number n is: "<<fibo(n)<<endl;
return 0;
}

int fibo(int n){
int *arr=new int[n+1];
if (n<0)
   return 0;

if (n<2){
arr[n]=n;
return n;
}

if (arr[n] != 0){
return arr[n];
}

arr[n]=fibo(n-1)+fibo(n-2);
return arr[n];
}
