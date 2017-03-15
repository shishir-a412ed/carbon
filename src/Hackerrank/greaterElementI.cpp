// Problem Description: https://leetcode.com/articles/greater-element-i
// Size of findNums=M.
// Size of nums=N.
// Time Complexity O(M*N). Space Complexity O(M).

#include <iostream>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> findNums, vector<int> nums){
vector<int> result;
int i,j,k;
for(i=0;i<findNums.size();i++){
    for(j=0;j<nums.size();j++){
	if (findNums[i]==nums[j])
	   break;
	}
    int max=findNums[i];
    for(k=j+1;k<nums.size();k++)
    {
    if (nums[k] > max)
       max=nums[k];
       break;
    }

    if (max == findNums[i])
       max=-1;
    result.push_back(max);
}
return result;
}

int main(){
vector<int> findNums={2,4};
vector<int> nums={1,2,3,4};
vector<int> result=nextGreaterElement(findNums, nums);
for(int i=0;i<result.size();i++)
   cout<<result[i]<<" ";
cout<<endl;
return 0;
}

