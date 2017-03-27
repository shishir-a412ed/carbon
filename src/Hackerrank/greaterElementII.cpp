// Problem Description: https://leetcode.com/articles/greater-element-i
// Size of findNums=M.
// Size of nums=N.
// Time Complexity O(M+N). Space Complexity O(M+N).

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums){
vector<int> result;
stack<int> st;
int i,j;
unordered_map<int,int> m;
unordered_map<int,int>::iterator it;

if (nums.empty())
   return result;

st.push(nums[0]);
for(i=1;i<nums.size();i++){
   while(!st.empty() && nums[i]>st.top()){
	int top=st.top();
	st.pop();
	m[top]=nums[i];
   }
   st.push(nums[i]);
}

for(j=0;j<findNums.size();j++){
   it=m.find(findNums[j]);
   if (it == m.end())
      result.push_back(-1);
   else
      result.push_back(it->second);
}
return result;
}

int main(){
vector<int> findNums={4,1,2};
vector<int> nums={1,3,4,2};
vector<int> result=nextGreaterElement(findNums, nums);
for(int i=0;i<result.size();i++)
   cout<<result[i]<<" ";
cout<<endl;
return 0;
}

