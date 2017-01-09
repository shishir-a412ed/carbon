#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool hasPairUnsorted(vector<int>, int);

int main(){
int sum;
vector<int> v={1,2,4,4};
cout<<"Original Vector:\n";
for(int i=0;i<v.size();i++)
   cout<<v[i]<<" ";
cout<<"\nEnter target sum\n";
cin>>sum;
if (hasPairUnsorted(v,sum))
{
cout<<"Pair exists\n";
}else{
cout<<"Pair does not exist\n";
}
return 0;
}

bool hasPairUnsorted(vector<int> v, int sum)
{
unordered_set<int> s;
unordered_set<int>::iterator it;
for(int i=0;i<v.size();i++)
{
it=s.find(sum-v[i]);
if (it == s.end())
{
s.insert(v[i]);
}else{
return true; 
}
}
return false;
}
