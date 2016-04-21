// Author: <fill in your name>
// Source File: stats.cpp
// Description: Various array statistics

#include <cmath>
using namespace std;



  
int arrSum(int array[], unsigned length){
  int sum = 0;
  for(unsigned count = 0; count < length ; count++){
    sum += array[count];
  }
  return sum;
}


double arrMean(int array[], unsigned length){
  double mean = 0;
  if(length == 0){
  mean = 0;
  }else if(length > 0){
  mean = (arrSum(array, length))/((float)length);
  }
  return mean;  
}

int arrMin(int array[], unsigned length){
  int min = array[0];
  if(length ==0){
    return 0;
  }
  for(unsigned count =1; count < length; count++){
    if(array[count] < min){
      min = array[count];
    }
  }
  return min;
}

int arrMax(int array[], unsigned length){
  int max = array[0];
  if(length ==0){
  return 0;
  }
  for(unsigned count =1; count < length; count++){
    if(array[count] > max){
      max = array[count];
    }
  }
  return max;
}


double arrStdDev(int array[], unsigned length){
  double sigma=0;
  double inside =0;
  double stdev =0;
  for(unsigned count =0; count < length; count++){
    sigma += (array[count]-arrMean(array, length))*(array[count]-arrMean(array, length));
    inside= (sigma/length);
    stdev=sqrt(inside);
  }
  return stdev;
}

bool isPrime(int number){
  bool TEST;
  TEST = true;
  if(number<=1){
    TEST = false;
  }
    for(int i=2; i < number; i++){
      //not prime:
      if (number%i==0){
        TEST = false;
      break;
        }
    //prime:
      else if (number%i!=0){
        TEST = true;
      }
    }
  return TEST;
}

unsigned arrNumPrimes(int array[], unsigned length){
  int numprime=0;
  for(unsigned count =0; count < length; count++){
    if (isPrime(array[count])){
    numprime+=1;
    }
  }
  return numprime;
}


unsigned arrSetSize(int array[], unsigned length){
  if (length==0){
    return 0;
  }
  int duplicates = 0;
  for(unsigned count = 0; count < length-1; count++){  
    for(unsigned i = count+1; i < length; i++){
      if(array[i]==array[count]){
        duplicates+=1;
        break;
      }
    }
  }
  int setsize=length-duplicates;
  return setsize;
}

unsigned arrNumCount(int array[], unsigned length, int num){
//return the number of times the value is in the array
int duplicates = 0;
  if(length==0){
    return 0;
  }
  for(unsigned count = 0; count < length; count++){  
    if( array[count] == num){
      duplicates+=1;
    }
  }
  return duplicates;
}



// For HW

unsigned arrNumBetween(int array[], unsigned length, int low, int high){
//given array, length, low val, and high val
//1. return # of values that are >= low 
//& # of values that are <= high 
//return the number of times the value is in the array
int numcount=0;
  if(length==0){
//    return 0;
  }
  for(unsigned count = 0; count < length; count++){  
    if(array[count] >= low && array[count] < high){
      numcount+=1;
    }
  }
  return numcount;
}



//Given an int array and its length, reverse the array in-place.  
//Because arrays act like pass-by-reference, if you reverse the order of the given array, 
//the array that was originally sent will also get reversed.  This returns nothing (void)

void arrReverse(int array[], int length){
  if(length==0){
//    return;
  }
  for(int count=0;count<length/2;count++){
    int newvalue=length-1-count; //if array[5]= {1, 2, 3, 4, 5} newvalue=4
    int newarr=array[newvalue];//newarr = array[4]
    array[newvalue]=array[count]; //array[4]= array[0] --> array[newval=4]=1 {-,-,-,-,1}
    array[count]=newarr; //array[count=0]=5 -->{5,-,-,-,1} 
    //keep swapping them until it reaches the length/2 - which is the middle one, which stays the same
  }
  for(int count=0;count<length;count++){
  }
  return;
}


//Given an int array, its length, a value, and a starting position, 
//return the position greater than or equal to the starting position in the array that matches the value.  
//If no starting position is given, use 0.  If the given value is not in the array, return -1.
int arrFind(int array[], unsigned int length, int value, unsigned int position=0){
  if (length==0){
    return 0;
  }
  else if(position>=length){
    return -1;
  }
  int j;
  int k;
  int p;
  for(unsigned int i = position; i < length; i++){
    if(i>=position && array[i]==value){
      k=i;
      p=k;
      break;
    }
    else if(array[i]!=value){
      j=-1;
      p=j;
      //continue;
    }
  }
  if(p==k){
    return k;
  }else if(p==j){
    return j;
  }
  return 0;
}





