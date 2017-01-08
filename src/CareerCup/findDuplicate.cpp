#include <iostream>
#include <unordered_set>

using namespace std;

void getDuplicatesExpo(int *,int, unordered_set<int>*);

int main(){
int a[]={2,4,3,2,1,5,4,8,0,1};
int size=sizeof(a)/sizeof(a[0]);
unordered_set<int> v;
unordered_set<int>::iterator it;
getDuplicatesExpo(a, size, &v);
for(it=v.begin();it != v.end(); it++)
   cout<<*it<<" ";
cout<<"\n";
return 0;
}

// Find duplicates in exponential time. Most naive solution.
// Time Complexity O(n^2)
// Space Complexity O(n)
void getDuplicatesExpo(int *a, int size, unordered_set<int> *v)
{
unordered_set<int>::iterator it;
for(int i=0;i<size;i++)
{
  for(int j=0;j<size;j++)
  {
  if (i==j)
     continue;
  else if (*(a+i)==*(a+j)){
          it=(*v).find(*(a+i));
          if (it == (*v).end())
	  {
          (*v).insert(*(a+i));  
          } 
   break;
   }
   }
}
}
