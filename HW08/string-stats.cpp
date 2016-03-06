// Author: <fill in your name>
// Source File: string-stats.cpp
// Description: Various string statistics
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <vector>


using namespace std;

unsigned numLines(const string& st){
  int n=1;
  int length = st.size();
  if(length == 0){
    n = 0;
  }else{
    for(int count = 0; count <= length; count++){
      if(st[count+1] == 0){
      }else if(st[count] == '\n'){
        n++;
      }
    }
  }
  return n;
}

unsigned upperCaseChars(const string& st){
  int u=0;
  int length = st.size();
  for(int count = 0; count <= length; count++){
    if(isupper(st[count])){
    u++;
    }
  }
  return u;
}

unsigned lowerCaseChars(const string& st){
  int l=0;
  int length = st.size();
  for(int count = 0; count <= length; count++){
    if(islower(st[count])){
    l++;
    }
  }
  return l;
}


unsigned numPunct(const string& st){
  int p=0;
  int length = st.size();
  for(int count = 0; count <= length; count++){
    if(ispunct(st[count])){
    p++;
    }
  }
  return p;
}

unsigned numWords(const string& st){
int w=0;
int length = st.size();
for(int count = 0; count < length; count++){
  if(length==0){
    w=0;
   }
  if((isalpha(st[count])) && ((st[count+1])=='-')){
    isspace(st[count+1]);
  }
  if((isalpha(st[count])) && !(isalpha(st[count+1]))){
    w++;
  }
}
return w;
}



vector<int> characterCounts(const string& st){
  vector<int> ret(26);
  int alphsize = ret.size();
  int stsize = st.size();
  for(int k = 0; k < alphsize; k++){
    for(int j = 0; j < stsize; j++){
      char letter = 'a' + k;
      if(tolower(st[j])==letter){
        ret[k]++;
      }
    }
  }
  return ret;
}

