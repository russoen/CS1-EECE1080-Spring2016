// Author: Fill name in here
// Source File: Crypto.h
// Description: Implements text encryption and decryption using different
// methods

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

#include "Crypto.h"

using namespace std;

Crypto::Crypto(const string& key_temp){
  key = key_temp;
}

string Crypto::caesarEncrypt(const string& input){
  string encrypt = input;
  int offset = ascii(key);
  for(unsigned int i = 0; i < input.length(); i++){
    int c = static_cast<int>(input[i]); //c++ way to convert chars
    if( c >= 'a' && c <= 'z'){
      c = c + offset; //note: z+5 is out of the range (alphabet range 1-26)
      c = (c - 'a') % 26;
      while(c < 0){
        c = c + 26;
      }
      c = c + 'a'; 
    }else  if( c >= 'A' && c <= 'Z'){
      c = c + offset;
      c = (c - 'A') % 26;
      c = c + 'A'; 
      while(c < 0){
        c = c + 26;
      }
    }
    encrypt[i]=c;
  }
  return encrypt;
}

string Crypto::caesarDecrypt(const string& input){
  string decrypt = input;
  int offset = ascii(key);
  for(unsigned int i = 0; i < input.length(); i++){
    int c = static_cast<int>(input[i]); //c++ way to convert chars
    if( c >= 'a' && c <= 'z'){
      c = c - offset + 26; //note: z+5 is out of the range (alphabet range 1-26)
      c = (c - 'a') % 26;
      while(c < 0){
        c = c + 26;
      }
      c = c + 'a'; 
    }else  if( c >= 'A' && c <= 'Z'){
      c = c - offset + 26;
      c = (c - 'A') % 26;
      c = c + 'A';
      while(c < 0){
        c = c + 26;
      }
    }
    decrypt[i]=c;
  }
  return decrypt;
}

string Crypto::vigenereEncrypt(const string& input){
  string code = input;
  unsigned int key_length = key.length();
  unsigned int input_length = input.length();
  for(unsigned i = 0; i < input_length; i++){
    if(isalpha(input[i])){
      int offset = key[i % key_length];
      if(isupper(input[i])){
        code[i] = (offset + input[i] - 'A') % 26 + 'A';
      }else if(islower(input[i])){
        code[i] = (offset + input[i] - 'a') % 26 + 'a';
      }
    }else if(!isalpha(input[i])){
      code[i] = input[i];
    }
    return code;
  } return code;
}
string Crypto::vigenereDecrypt(const string& input){
  string code = input;
  int key_length = key.length();
  for(unsigned int i = 0; i < code.length(); i++){
    if(isalpha(input[i])){
      int offset_point = i % key_length;
      int offset = (key[offset_point]) * -1;
        while(offset < 0){
          offset = offset + 26;
        }
      if(isupper(input[i])){
        code[i] = (offset + 'A' - input[i]) % 26 - 'A';
      }else if(islower(input[i])){
        code[i] = (offset - 'a' + input[i]) % 26 + 'a';
      }
    }else if(!isalpha(input[i])){
      code[i] = input[i];
    }
    return code;
  } return code;
}

// Count the letter frequencies (all lower), then return the
// StDev of the result.
// Return 0.0 if the string is empty.
double Crypto::letterFreqStDev(const string& input){
  return 0.0;
}
  /*int count = 0;
  for(int i = 0; input[i] != '\0'; ++i){
    for(int j = 0; input[j] < input.length; ++i){
      if(input[j]==input[i])
        ++count;
     } return count;
 }
}*/
