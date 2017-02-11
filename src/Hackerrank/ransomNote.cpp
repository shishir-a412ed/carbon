// Given an arbitrary ransom note string and another string containing letters from all the magazines,
// Write a function that will return true if the ransom note can be constructed from the magazines;
// otherwise, it will return false.
// Each letter in the magazine string can only be used once in your ransom note.
// NOTE: You may assume that both strings contain only lowercase letters.

#include <iostream>
#include <string>

using namespace std;

bool canConstruct(string, string);

int main(){
string ransomNote, magazine;
cout<<"Enter string RANSOM_NOTE:\n";
getline(cin, ransomNote);
cout<<"Enter string MAGAZINE\n";
getline(cin, magazine);
if (canConstruct(ransomNote,magazine))
	cout<<"TRUE\n";
else
	cout<<"FALSE\n";
return 0;
}

bool canConstruct(string ransomNote, string magazine) {
int r[26], m[26];
int i,j,k;
for(i=0;i<26;i++){
    r[i]=0;
    m[i]=0;
}
// Populate ransomNote frequencies.
for(j=0;j<ransomNote.length();j++){
    r[int(ransomNote[j])-97]++;
   }
// Populate magzine frequencies.
for(k=0;k<magazine.length();k++){
            m[int(magazine[k])-97]++;
        }
// Check if ransom note can be constructed from the magazine characters.
for (i=0;i<26;i++){
            if (r[i]<=m[i]){
                continue;
            }
            return false;
        }
return true;
}
