// Author: Elle Russo
// Source File: mylib.cpp
// Description: Lab 5 unit tests 1

#include <iostream>
#include <cmath>


using namespace std;


const double PI = atan(1.0)*4.0;
const double PRECISION = 0.00001;

// For lab....
//FACTORIAL
double factorial(double n){
  double fact = 1.0;
  if(n == -1){
    return -1.;
  }
  for(double i =1 ; i <= n; i++){
    fact = fact*i;
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
  return sin(z);
}


// For HW.....
//My Sine
double mySine(double x) {
  double previous = 0, current = x;
  double sign = 2;
	while (fabs(current - previous) > .0001) {
		previous = current;
		current = current - (pow((-1.0), sign) * (pow(x, ((sign * 2) - 1))) / factorial((sign * 2) - 1));
		sign++;
	}
	return current;
}



//System Cosine
double systCosine(double y){
  return cos(y);
}

// myCos
double myCosine(double y){
	double previous = 0, current = 1;
	double exponent = 2;
	int sign = 2;
	while (fabs(current - previous) > .0001) {
		previous = current;
		current = current - (pow((-1.0), sign) * (pow(y, exponent)) / factorial(exponent));
		exponent+=2;
		sign++;
	}
	return current;
}

