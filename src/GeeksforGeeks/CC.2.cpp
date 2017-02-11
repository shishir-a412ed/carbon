/*
Given two integer arrays list1 and list2 and an int target value. WAP to
check if there exists such a sum, where one number taken from list1 and other
from list2 to add up to become the target value. Return true if so, else return
false.
*/

// Time Complexity: O(n).

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> populateList();
bool checkTargetSum(vector<int>, vector<int>, int);

int main()
{
vector<int> v1, v2;
int val;
bool result=false;
v1 = populateList();
v2 = populateList();
cout<<"Enter target value"<<endl;
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

bool checkTargetSum(vector<int> v1, vector<int> v2, int target)
{
vector<int>::iterator i,j;
unordered_set<int> mset;
unordered_set<int>::iterator found;
for (i=v1.begin(); i!= v1.end(); i++)
{
mset.insert(*i);
}
for (j=v2.begin(); j!=v2.end(); j++)
{
found=mset.find(target-(*j));
if (found == mset.end())
	continue;
else
	return true;
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


