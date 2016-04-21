#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Given a comma separated string break the large string into individual strings 
//demarcated by a comma and store them into a vector.  
//Consider using the find and substr functions
vector <string> breakup(string s){
  vector <string> inString;
  int start = 0;
  for(unsigned int i = 0; i < s.size(); i++){
    if(s[i] == ','){
      inString.push_back(s.substr(start, i-start));
      start = i+1;
    }    
  }inString.push_back(s.substr(start));
  return inString;
}
//1. Produce a count of words that start with a specific letter (case insensitive)
int countStart(string s, char l){
  vector <string> brokenString = breakup(s);    
  if(isupper(l)){
    l = tolower(l);
  }
  int count = 0;
  for(unsigned int i = 0; i < brokenString.size(); i++){ //outside goes thru each string in the vector
    string current = brokenString[i];
    int firstLetter = 0;
    if(isupper(current[firstLetter])){
      current[firstLetter] = tolower(current[firstLetter]);
    }
    if(current[firstLetter] == l){
      count++;
    }
  }return count;
}


//2. Produce a count of words that contain a specific letter
int countContain(string s, char l){
  vector <string> brokenString = breakup(s);    
  if(isupper(l)){
    l = tolower(l);
  }
  int count = 0;
  for(unsigned int i = 0; i < brokenString.size(); i++){ //outside goes thru each string in the vector
    string current = brokenString[i];
    for(unsigned int j = 0; j < brokenString.size(); j++){//inside goes thru first char in the string
      if(isupper(current[j])){
        current[j] = tolower(current[j]);
      }
      if(current[j] == l){
        count++;
        break;
      }
    }
  }return count;
}

//3. Return the first string in the vector that contains a specific letter. 
//   Please return proper error code if a string is not found.
string stringContain(string in, char l){
  vector <string> brokenString = breakup(in);    
  if(isupper(l)){
    l = tolower(l);
  }
  for(unsigned int i = 0; i < brokenString.size(); i++){ //outside goes thru each string in the vector
    string current = brokenString[i];
    for(unsigned int j = 0; j < current.size(); j++){ //inside goes thru each char in the string
      if(isupper(current[j])){
        current[j] = tolower(current[j]);
      }
      if(current[j] == l){
        current = brokenString[i];
        return current;
      }
    }
  }
  return "none of the strings contain that letter.";
}
//4. Return the first string that is alphabetically the largest (use the > operator)
string stringAlph(string in){
  vector <string> brokenString = breakup(in);
  string largest = "";
  for(unsigned int i = 0; i < brokenString.size(); i++){ //outside goes thru each string in the vector
    largest = brokenString[i];
    for(unsigned int j = 1; j < brokenString.size()-1; j++){
      if(largest > brokenString[j]){
      }else if(brokenString[j] > largest){
        largest = brokenString[j];
      }else{break;}
    }
  }return largest;
}
//5. Return the ASCII sum of all letters in a specific string
double countASCII(string in, unsigned int number){
  vector <string> brokenString = breakup(in);
  if(number >= brokenString.size() || number < 0){
    return -1;
  }
  string stringSelection = brokenString[number];
  double sum = 0.0;
  for(unsigned int i = 0; i < stringSelection.size(); i++){
    sum += static_cast<double>(stringSelection[i]);
  } return sum;
}
//6. Write main() to exersize functions, they should all be called at least once
int main(){
  //string breakup
  string in;
  cout << "Enter string with commas: ";
  cin >> in;
  vector <string> myString = breakup(in);
  for(unsigned int i = 0; i < myString.size(); i++){
    cout << myString[i] << endl;
  }
  //1. word count starting with a specific letter
  char a;
  cout << "Enter a letter: ";
  cin >> a;
  cout << "Num of words starting with "<< a << ": " << countStart(in, a) << endl;
  //2. word count containing a specific letter
  char b;
  cout << "Enter another letter: ";
  cin >> b;
  cout << "Num of words that contain "<< b << ": " << countContain(in, b) << endl;
  //3. First string that contains a specific letter
  char c;
  cout << "Enter another letter: ";
  cin >> c;
  cout << "First string that contains "<< c << ": " << stringContain(in, c) << endl;
  //4. First string that is alphabetically the largest (use the > operator)
  cout << "The alphabetically largest word is: " << stringAlph(in) << endl;
  //5. Return the ASCII sum of all letters in a specific string
  int num = 0;
  cout << "Enter the number of a certain string (base 0): ";
  cin >> num;
  cout << "The ASCII sum of all letters in this string is: " << countASCII(in, num) << endl;
  return 0;
}



