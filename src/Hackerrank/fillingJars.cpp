/*
https://www.hackerrank.com/challenges/filling-jars
*/

#include <iostream>

using namespace std;

int main()
{
unsigned long jars, ops, a, b, k, result=0;
cin>>jars>>ops;
int i;
for(i=0;i<ops;i++)
{
cin>>a>>b>>k;
result=result+((b-a)+1)*k;
}
cout<<"Average number of candies across "<<jars<<" jars: "<<(result/jars)<<endl;
return 0;
}
