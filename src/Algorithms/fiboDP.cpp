// This solution calculates fibonacci number F(n)
// using dynamic programming bottom up approach.

#include <iostream>
#include <stdlib.h>

using namespace std;

int calcFibonacci(int);

int main(){
int n;
cout<<"Enter the value of n\n";
cin>>n;
cout<<"Fibonacci for number n is: "<<calcFibonacci(n)<<endl;
return 0;
}

int calcFibonacci(int n){
if (n<0)
{
cout<<"Invalid value of n: "<<n<<endl;
exit(EXIT_FAILURE);
}
if (n<2)
   return n;

int first=0;
int second=1;
int third;

for(int i=2;i<=n;i++){
third=first+second;
first=second;
second=third;
}
return third;
}
