// Vector v1 is in ascending order.
// Vector v2 is in descending order.
// Create a Vector v3 with elements of {v1, v2} in ascending order.

#include <iostream>
#include <vector>

using namespace std;
vector<int>* mergeVectors(vector<int>*, vector<int>*);
vector<int> v3;

int main()
{
vector<int> v1={0,10,20,50,60,70,80,90,99};
vector<int> v2={95,85,53,32,3};
vector<int> *v3=mergeVectors(&v1, &v2);
vector<int>::iterator it;
cout<<"Target vector v3\n";
for(it=(*v3).begin(); it != (*v3).end(); it++)
{
cout<<*it<<endl;
}
return 0;
}

vector<int>* mergeVectors(vector<int> *v1, vector<int> *v2)
{
vector<int>::iterator it1=(*v1).begin();
vector<int>::reverse_iterator it2=(*v2).rbegin();
while(it1!=(*v1).end() && it2!=(*v2).rend())
{
 if (*it1 <= *it2)
 {
 v3.push_back(*it1);
 it1++;
 }
 else
 {
 v3.push_back(*it2);
 it2++;
 }
}
// Insert leftover elements of v2 into v3.
if (it1==(*v1).end())
{
 while (it2 != (*v2).rend())
 {
 v3.push_back(*it2);
 it2++;
 }
}
// Insert leftover elements of v1 into v3.
if (it2==(*v2).rend())
{
 while (it1 != (*v1).end())
 {
 v3.push_back(*it1);
 it1++;
 }
}
return &v3;
}

