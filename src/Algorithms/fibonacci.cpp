// Compute fibonacci number using recursion.
#include <iostream>

using namespace std;

int calcFibonacci(int);

int main(){
int result, n;
cout<<"Enter the value of n:\n";
cin>>n;
result=calcFibonacci(n);
cout<<"Fibonacci number n is: "<<result<<endl;
return 0;
}

int calcFibonacci(int n){
if (n==0)
   return 0;
if (n==1)
   return 1;
return calcFibonacci(n-1)+calcFibonacci(n-2);
}
