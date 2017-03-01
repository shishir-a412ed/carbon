// Give a sorted array of numbers {2, 5, 11, 14, 17, 20, 55, 78, 100}
// and a target sum, find two numbers {a, b} where a+b is closest to
// the target sum.

// Time Complexity O(n). Space Complexity O(1).

#include <iostream>
#include <utility>
#include <climits>

using namespace std;

pair<int,int> getClosestSum(int a[], int size, int target){
int i=0;
int j=size-1;
int maxDiff=INT_MAX;
int currDiff,x,y;
bool sumGreater;
pair<int,int> result;
while(i != j){
	sumGreater=false;
	int sum=a[i]+a[j];
	if (sum == target){
		x=a[i];
		y=a[j];
		break;
	}else if (sum > target){
		currDiff = sum-target;
		sumGreater=true;
	}else{
		currDiff=target-sum;
	}
	if (currDiff < maxDiff){
	   x=a[i];
	   y=a[j];
           maxDiff = currDiff;
	}
	if (sumGreater)
	   j--;
	else
	   i++;
}
result=make_pair(x,y);
return result;
}

int main(){
int a[]={2, 5, 11, 14, 17, 20, 55, 78, 100};
int size=sizeof(a)/sizeof(a[0]);
int target;
pair<int,int> result;
cout<<"Original array is :\n";
for(int i=0;i<size;i++)
	cout<<a[i]<<" ";
cout<<"\nEnter target sum\n";
cin>>target;
result=getClosestSum(a, size, target);
cout<<"Elements closest to the target sum are: "<<result.first<<" "<<result.second<<endl;
cout<<"Closest sum is: "<<result.first+result.second<<endl;
return 0;
}
