#ifndef MANIP_H
#define MANIP_H

// Author: Fill in your name
// Source File: manip.h
// Description: A set of functions where you should manipulate
// the passed parameters to change the object in a specific way, 
// so that Pointers_test.h passes all tests.

#include "Pointers.h"

void manip1(Pointers* p){
  *(p->getA()) = 10;
}

void manip2(Pointers* p){
  *(p->getB()) = 45;
}

void manip3(Pointers* p){
  *(p->getB()) = *(p->getA());
}

void manip4(Pointers* p, int* other){
  (p->setB(other));
}

void manip5(Pointers* p, int* other){
  *(p->getB()) = 45;
  p->setC();
  p->getC();
}

void manip6(Pointers* p){
  *(p->getB() + 2) = 10;
}

void manip7(Pointers* p){
  *(p->getB()) = 15;
}

void manip8(Pointers* p){
  *(p->getA()) = 199;
  (p->setB(p->getA()));
  p->setC();
}

void manip9(Pointers* p, int* other){
  p->setB(other);
}

void manip10(Pointers* p){
  *(p->getA()) = 199;  
  (*(p+5)).setB(p->getA());
  (*(p+5)).setC();
}

#endif
