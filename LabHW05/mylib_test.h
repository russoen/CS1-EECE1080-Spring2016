#ifndef MYLIB_TEST_H
#define MYLIB_TEST_H

#include <mylib.cpp>
#include <cmath>
#include <iostream>
#include <cxxtest/TestSuite.h>

using namespace std;

// This requires CxxTest to be installed!
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.


class MyTests : public CxxTest::TestSuite {
public:
//Test Factorial Function
  void testFact1() {
    TS_ASSERT_DELTA(factorial(1), 1.0, 0.01);
  }
  
  void testFact2() {
    TS_ASSERT_DELTA(factorial(5), 120.0, 0.01);
  }
  
    void testFact3() {
    TS_ASSERT_DELTA(factorial(12), 479001600.0, 0.01);
  }
  
  void testFact4() {
    TS_ASSERT_EQUALS(factorial(-1), -1.0);
  }
  
  void testFact5(){
    TS_ASSERT_EQUALS(factorial(8),40320.0);
  }
    void testFact6(){
    TS_ASSERT_EQUALS(factorial(3),6);
  }
    
//Test Degrees to Radians Function
  void testDTR1() {
    TS_ASSERT_DELTA(degreesToRadians(45),0.7853,0.0001);
  }
  
  void testDTR2() {
    TS_ASSERT_DELTA(degreesToRadians(-45),-0.7853,0.0001);
  }
  
    void testDTR3() {
    TS_ASSERT_DELTA(degreesToRadians(0),0.0, 0.0001);
  }
  
  void testDTR4() {
    TS_ASSERT_DELTA(degreesToRadians(360),0.0, 0.0001);
  }
  
  void testDTR5(){
    TS_ASSERT_DELTA(degreesToRadians(60),1.0471, 0.0001);
  }
    void testDTR6(){
    TS_ASSERT_DELTA(degreesToRadians(120),2.0943, 0.0001);
  }

//Test Prime function
    void testPrime1(){
    TS_ASSERT_EQUALS(isPrime(9),false);
  }
      void testPrime2(){
    TS_ASSERT_EQUALS(isPrime(6),false);
  }
      void testPrime3(){
    TS_ASSERT_EQUALS(isPrime(2),true);
  }
      void testPrime4(){
    TS_ASSERT_EQUALS(isPrime(0),false);
  }
      void testPrime5(){
    TS_ASSERT_EQUALS(isPrime(1),false);
  }
      void testPrime6(){
    TS_ASSERT_EQUALS(isPrime(-10),false);
  }


//Test System Sine function
    void testSystemSine1(){
    TS_ASSERT_DELTA(systSine(45),.7071, 0.0001);
  }
    void testSystemSine2(){
    TS_ASSERT_DELTA(systSine(0),0.0, 0.0001);
  }
    void testSystemSine3(){
    TS_ASSERT_DELTA(systSine(90),1.0000, 0.0001);
  }  
    void testSystemSine4(){
    TS_ASSERT_DELTA(systSine(-90),-1.0000, 0.0001);
  }
    void testSystemSine5(){
    TS_ASSERT_DELTA(systSine(360),0.0000, 0.0001);
  }
    void testSystemSine6(){
    TS_ASSERT_DELTA(systSine(270),-1.0000, 0.0001);
  }
  
//Test My Sine function
    void testmySine1(){
    TS_ASSERT_DELTA(mySine(45),.7071, 0.0001);
  }
    void testmySine2(){
    TS_ASSERT_DELTA(mySine(0),0.0, 0.0001);
  }
    void testmySine3(){
    TS_ASSERT_DELTA(mySine(90),1.0000, 0.0001);
  }  
    void testmySine4(){
    TS_ASSERT_DELTA(mySine(-90),-1.0000, 0.0001);
  }
    void testmySine5(){
    TS_ASSERT_DELTA(mySine(360),0.0000, 0.0001);
  }
    void testmySine6(){
    TS_ASSERT_DELTA(mySine(270),-1.0000, 0.0001);
  }
/Test System Cosine Function
    void testsystemCosine1(){
    TS_ASSERT_DELTA(systCosine(45),.5253, 0.0001);
  }
    void testsystemCosine2(){
    TS_ASSERT_DELTA(systCosine(0),1.0000, 0.0001);
  }
    void testsystemCosine3(){
    TS_ASSERT_DELTA(systCosine(90),0.0000, 0.0001);
  }
    void testsystemCosine4(){
    TS_ASSERT_DELTA(systCosine(180),-1.0000, 0.0001);
  }
    void testsystemCosine5(){
    TS_ASSERT_DELTA(systCosine(-45),-.7071, 0.0001);
  }

//Test my Cosine function
    void testMyCosine1(){
    TS_ASSERT_DELTA(myCosine(45),.7071, 0.0001);
  }
    void testMyCosine2(){
    TS_ASSERT_DELTA(myCosine(0),1.0000, 0.0001);
  }
    void testMyCosine3(){
    TS_ASSERT_DELTA(myCosine(90),0.0000, 0.0001);
  }
    void testMyCosine4(){
    TS_ASSERT_DELTA(myCosine(180),-1.0000, 0.0001);
  }
    void testMyCosine5(){
    TS_ASSERT_DELTA(myCosine(-45),.7071, 0.0001);
  }


//End 
};


#endif
