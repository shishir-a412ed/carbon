// Min cost path in a cost path matrix.
// http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/

#include <iostream>
#include <climits>

using namespace std;

int minCost(int [3][3], int, int);
int min(int, int, int);

int main(){
int cost[3][3] = { {1,2,3},
 		 {4,8,2},
                 {1,5,3} };
cout<<"Cost of minimum cost path: "<<minCost(cost, 2, 2)<<endl;
return 0;
}

int minCost(int cost[3][3], int m, int n){
if (m<0 || n<0)
   return INT_MAX;
if (m==0 && n==0)
   return cost[m][n];
return cost[m][n] + min(minCost(cost,m,n-1), minCost(cost,m-1,n-1), minCost(cost,m-1,n));
}

int min(int a, int b, int c){
if (a < b){
      if (a < c)
	 return a;
      else
         return c;  
}else if (b < c)
         return b;
      else
         return c;
} 
