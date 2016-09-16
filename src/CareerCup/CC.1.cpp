/*
Given two integer arrays list1 and list2 and an int target value. WAP to
check if there exists such a sum, where one number taken from list1 and other
from list2 to add up to become the target value. Return true if so, else return
false.
*/

// Time Complexity: O(n^2).

#include <iostream>
#include <vector>

using namespace std;

vector<int> populateList();
bool checkTargetSum(vector<int>, vector<int>, int);

int main()
{
vector<int> v1, v2;
int val;
v1 = populateList();
v2 = populateList();
bool result=false;
cout<<"Enter target value\n";
cin>>val;
result = checkTargetSum(v1, v2, val);
if (result)
{
cout<<"Target sum exists\n";
}else
{
cout<<"Target sum does not exist\n";
}
return 0;
}

bool checkTargetSum(vector<int> v1, vector<int> v2, int val)
{
vector<int>::iterator i,j;
for(i=v1.begin();i!=v1.end();i++)
{   
for(j=v2.begin();j!=v2.end();j++)
   {
   if((*i)+(*j)==val)
     {
     return true;
     }
   }
}
return false;
}
		
vector<int> populateList()
{
vector<int> v;
int i, n, val;
cout<<"Enter the number of elements you would like to insert in the list\n";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"Enter element\n";
cin>>val;
v.push_back(val);
}
return v;
}
