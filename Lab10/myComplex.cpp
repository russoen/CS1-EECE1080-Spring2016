// Author: Fill name in here
// Source File: myComplex.cpp
// Description: Implements complex number class, capable of doing typical
// operations using overloaded operators.

#include <iostream>
#include <cmath>
#include <sstream>

#include "myComplex.h"

using namespace std;

static const double eq_delta = 0.0001;

// TODO: Fill in the rest of the class methods!

void myComplex::displayPolar() const {
  cout << getMagnitude();
  cout << "@ "  << getAngle() << endl;
}
//A default Constructor that sets the complex number to 0
myComplex::myComplex(){
  setComplex(0.0,0.0);
}
//Constructor that takes a single double for the real part of complex number and sets the Imaginary=0
myComplex::myComplex(double in_real){
  imaginary = 0.0;
  real = in_real;
}
//Constructor that takes two doubles (real and imaginary parts of a complex number).
myComplex::myComplex(double in_real, double in_imaginary){
  imaginary = in_imaginary;
  real = in_real;
}
//getReal() - returns real part of complex number as a double.
double myComplex::getReal()const{
  return real;
}
//getImaginary() - returns imaginary part of number as a double.
double myComplex::getImaginary()const{
  return imaginary;
}
//getMagnitude() - returns the magnitude of the polar form of the number
double myComplex::getMagnitude()const{
  double magnitude = sqrt((real*real)+(imaginary*imaginary));
  return magnitude;
}
//getAngle() - returns the angle of the polar form of the number
double myComplex::getAngle()const{
  const double PI = 3.14159;
  double radians = atan(imaginary/real);
  double degrees = (180/PI)*radians;
  double angle = degrees;
  if(imaginary == 0.0 && real == 0.0){
    angle = 0;
  }
  return angle;
}
//setReal() - sets the real part of the complex number
void myComplex::setReal(const double in_real){
  imaginary = 0.0;
  real = in_real;
}
//setImaginary() - sets the imaginary part of the complex number
void myComplex::setImaginary(const double in_imaginary){
  imaginary = in_imaginary;
  real = 0.0;
}
//setComplex() - sets both real and imaginary parts of a complex number
void myComplex::setComplex(const double in_real, const double in_imaginary){
  imaginary = in_imaginary;
  real = in_real;
}
//addition -- They all take a myComplex object and return a myComplex object.
myComplex myComplex::addition(const myComplex right){
  myComplex retval;
  retval.real = real + right.real;
  retval.imaginary = imaginary + right.imaginary;
  return retval;
}

//subtraction
myComplex myComplex::subtraction(const myComplex right){
  myComplex retval;
  retval.real = real - right.real;
  retval.imaginary = imaginary - right.imaginary;
  return retval;
}

//multiplication 
myComplex myComplex::multiplication(const myComplex right){
  myComplex retval;
  retval.real = (real * right.real) - (imaginary * right.imaginary);
  retval.imaginary = (real*right.imaginary) + (imaginary*right.real);
  return retval;
}

//division
myComplex myComplex::division(const myComplex right){
  myComplex retval;
  double denom = right.real*right.real + right.imaginary*right.imaginary;
  retval.real    = (real*right.real + imaginary*right.imaginary)/denom;
  retval.imaginary = (imaginary*right.real - real*right.imaginary)/denom;
  return retval;
}

string myComplex::display() const{
  stringstream retval;
  retval << "(" << real << " + " << imaginary << "i)";
  return retval.str();
}

//Operators: +
myComplex myComplex::operator+ (const myComplex& right){
  return(addition(right));
}
//Operators: -
myComplex myComplex::operator- (const myComplex& right){
  return(subtraction(right));
}
//Operator *
myComplex myComplex::operator* (const myComplex& right){
  return(multiplication(right));
}
//Operator /
myComplex myComplex::operator/ (const myComplex& right){
  return(division(right));
}
//conjugate() function which returns the conjugate of the current object.
myComplex myComplex::conjugate(){
  myComplex retval;
  retval.real = real;
  retval.imaginary = -1*imaginary;
  return retval;
}
// Operator ==
bool myComplex::operator== (const myComplex& right){

  double diff_real = abs(real - right.real);
  double diff_im = abs(imaginary - right.imaginary);

  return diff_real < eq_delta && diff_im < eq_delta;
}
// Operator !=
bool myComplex::operator!= (const myComplex& right){
  double diff_real = abs(real - right.real);
  double diff_im = abs(imaginary - right.imaginary);
  return diff_real > eq_delta || diff_im > eq_delta;
}

  
  
ostream& operator<<( ostream& output, const myComplex &thing ){
  output << thing.display();
  return output;
}
  
istream& operator>>( istream &input, myComplex &thing ){
  cout << "Enter Real Part: ";
  input >> thing.real;
  cout << "Enter Imaginary Part: ";
  input >> thing.imaginary;
  return input;
}


