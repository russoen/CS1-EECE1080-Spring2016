// Author: Elle Russo
// Source File: mylib.cpp
// Description: Lab 5 unit tests 1

#include <iostream>
#include <cmath>


using namespace std;

// TODO: You may implement any helper functions you like, or define
// 			or change any constant you like.

const double PI = atan(1.0)*4.0;
const double PRECISION = 0.00001;

// For lab....
//FACTORIAL
double factorial(double n){
  double fact = 1;
  for(int i = 1 ; i <= n; i++){
    fact = fact*i;
  }
  if(n< 0){
    return -1;
  }    
  return fact;
}

//DEGREES TO RADIANS
double degreesToRadians(double degrees){
  const double PI = (atan(1.0)*(4.0));
  double rads;
  //if input is + return a value 0-2PI not including 2PI
  if(degrees >= 0 && degrees <360){
    rads = degrees * PI/180;
    return rads;
  }
  else if(degrees >-360 && degrees <0){
    rads = degrees * PI/180;
    return rads;
  }
  else if(degrees>360){
    rads = (degrees-360) * PI/180; 
    return rads; 
  }
  else if(degrees<-360){
    rads = (degrees+360) *PI/180;
    return rads;  
  }
  else{
    return 0;
  }
}


//PRIME
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



//System Sine
double systSine(double z){
  double dtr = degreesToRadians(z);
  double sys_sin = sin(dtr);
  return sys_sin;
}



// For HW.....
//My Sine
double mySine(double y){
  double sign =1;
  double difference = 1;
  double previous;
  double current;
  int a, N = 1;
  current = 0;
  while(difference > .00001){
    sign = -1;
    previous = 1;
    for(a=1; a<N; a+=2){
    previous = previous-(pow(y,a)*sign)/(factorial(a));
    sign = (-1)*sign;
    }
    difference = fabs(previous - current);
    current = previous;
    N = N+2;

  }  
  return previous;
}


double myCosine(double x){
  double sign =1;
  double difference = 1;
  double previous;
  double current;
  int N =1;
  current = 0;
  while(difference > 0.00001){
    sign = -1;
    previous = 1;
      for(int a=2; a<N; a+= 2){
      previous = previous+(pow(x,a)*sign)/(factorial(a));
      sign = (-1)*sign;
      }
    difference = fabs(previous - current);
    current = previous;
    N = N+2;
  }
  return previous;
}


