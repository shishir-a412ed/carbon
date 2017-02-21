// Test if the input number is a power of 2.
// HINT: Bit manipulation.

#include <iostream>

using namespace std;

bool isPowerOfTwo(int);

int main()
{
int n;
cout<<"Enter a number\n";
cin>>n;
if (isPowerOfTwo(n))
   cout<<"Number is a power of 2\n";
else
   cout<<"Number is NOT a power of 2\n";
return 0;
}

bool isPowerOfTwo(int n){
   return ((n & n-1) == 0)?true:false;
}

