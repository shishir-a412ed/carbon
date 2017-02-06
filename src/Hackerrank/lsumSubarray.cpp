// Largest sum contigous subarray.
// This is a brute force solution. Time Complexity O(n^2) where n is the size of the array.
// This is not a very efficient algorithm.
// Kadane algorithm solves this in linear time O(n).

#include <iostream>
#include <vector>

using namespace std;

vector<int> subarraySum(int [], int);

int main(){
int a[]={-2,-3,4,-1,-2,1,5,-3};
int a1[]={-2,1,-3,4,-1,2,1,-5,4};
int size=sizeof(a1)/sizeof(a1[0]);
cout<<"Original Array\n";
for(int i=0;i<size;i++)
   cout<<a1[i]<<" ";
vector<int> result=subarraySum(a1, size);
cout<<"\nStart and end indexes of the largest sum contigous subarray: ";
for(int i=0;i<result.size()-1;i++)
   cout<<result[i]<<" ";
cout<<"\nSum of the contigous subarray: ";
cout<<result[result.size()-1]<<"\n";
return 0;
}

vector<int> subarraySum(int a[], int size){
	vector<int> result;
	int start_index=0, end_index=0;
	int max=0;
	int sum, sum_so_far, sum_so_far_i=0, sum_so_far_j=0;
	for(int i=0;i<size;i++){
   		sum=sum_so_far=0;
   		for(int j=i;j<size;j++){
      			sum_so_far=sum_so_far+a[j];
      			if (sum_so_far > sum)
			{
         		sum=sum_so_far;
	 		sum_so_far_i=i;
	 		sum_so_far_j=j;
			}
   		}
   		if (sum > max)
		{
      		max=sum;
      		start_index=sum_so_far_i;
      		end_index=sum_so_far_j;
   		}
	}
	result.push_back(start_index);
	result.push_back(end_index);
	result.push_back(max);
return result;
}
