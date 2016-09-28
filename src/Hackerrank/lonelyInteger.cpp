/*
https://www.hackerrank.com/challenges/lonely-integer
Time complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int lonelyinteger(vector<int>);

int main()
{
int size, i, val, res;
cin>>size;
vector<int> a;
for(i=0;i<size;i++)
{
cin>>val;
a.push_back(val);
}
res = lonelyinteger(a);
cout<<"Lonely integer is: "<<res<<endl;
return 0;
}

int lonelyinteger(vector<int> a)
{
unordered_set<int> m;
vector<int>::iterator i;
unordered_set<int>::iterator found;
for(i=a.begin(); i!=a.end(); i++)
{
found = m.find(*i);
if (found == m.end())
{
m.insert(*i);
}
else
{
m.erase(*i);
}
}
return *(m.begin());
}

