// Reverse words in a string using C++ STL string class.

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
string s;
stack<char> st;
cout<<"Enter the input string\n";
getline(cin, s);
cout<<"Reversed string is\n";
for(int i=s.length()-1;i>=0;i--){
   if (s[i] != ' '){
      st.push(s[i]);
      continue;
   }else{
    while(!st.empty()){
         cout<<st.top();
         st.pop();
       }
       cout<<" "; 
   }
}
while(!st.empty()){
   cout<<st.top();
   st.pop();
}
cout<<endl;
return 0;
}
