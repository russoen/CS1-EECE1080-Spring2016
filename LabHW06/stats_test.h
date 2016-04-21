#ifndef STATS_TEST_H
#define STATS_TEST_H

#include <iostream>
#include <cxxtest/TestSuite.h>

#include "stats.cpp"

using namespace std;

// This requires CxxTest to be installed!
// For this CPPVideos example, navigate your terminal to CPPVideos and type:
// git submodule add https://github.com/CxxTest/cxxtest.git
// This will add the public CxxTest repository INSIDE the current repo.
// The current Makefile in this directory assumes cxxtest is a folder one
// level down.


class MyTests : public CxxTest::TestSuite {
public:
//SUM
  void testSum1() {
    int a[] = {1,2,3};
    TS_ASSERT_EQUALS(arrSum(a, 3), 6);
  }
  
  void testSum2() {
    int a[] = {10,20,30,40};
    TS_ASSERT_EQUALS(arrSum(a, 4), 100);
  }
  void testSum3() {
    int a[] = {-2,200,56,-7, 12, 17};
    TS_ASSERT_DIFFERS(arrSum(a, 6), 200);
  }
  void testSum4() {
    int a[] = {};
    TS_ASSERT_EQUALS(arrSum(a, 0), 0);
  }
//MEAN
  void testMean1() {
    int a[] = {1,2,3};
    TS_ASSERT_EQUALS(arrMean(a, 3), 2);
  }
  
  void testMean2() {
    int a[] = {10,20,30,40};
    TS_ASSERT_EQUALS(arrMean(a, 4), 25);
  }
  void testMean3() {
    int a[] = {-2,200,56,-7, 12, 17};
    TS_ASSERT_DIFFERS(arrMean(a, 6), 200);
  }
  void testMean4() {
    int a[] = {};
    TS_ASSERT_EQUALS(arrMean(a, 0), 0);
  }
//MIN
  void testMin1() {
    int a[] = {1,2,3};
    TS_ASSERT_EQUALS(arrMin(a, 3), 1);
  }
  
  void testMin2() {
    int a[] = {10,20,30,40};
    TS_ASSERT_EQUALS(arrMin(a, 4), 10);
  }
  void testMin3() {
    int a[] = {-2,200,56,-7, 12, 17};
    TS_ASSERT_DIFFERS(arrMin(a, 6), 12);
  }
  void testMin4() {
    int a[] = {};
    TS_ASSERT_EQUALS(arrMin(a, 0), 0);
  }
    void testMin5() {
    int a[] = {-10,-20,-30,-40};
    TS_ASSERT_EQUALS(arrMin(a, 4), -40);
  }

//MAX
  void testMax1() {
    int a[] = {1,2,3};
    TS_ASSERT_EQUALS(arrMax(a, 3), 3);
  }
  
  void testMax2() {
    int a[] = {10,20,30,40};
    TS_ASSERT_EQUALS(arrMax(a, 4), 40);
  }
  void testMax3() {
    int a[] = {-2,200,56,-7, 12, 17};
    TS_ASSERT_DIFFERS(arrMax(a, 6), 56);
  }
  void testMax4() {
    int a[] = {};
    TS_ASSERT_EQUALS(arrMax(a, 0), 0);
  }
    void testMax5() {
    int a[] = {-10,-20,-30,-40};
    TS_ASSERT_EQUALS(arrMax(a, 4), -10);
  }


//STANDARD DEVIATION
  void testStdDev1() {
    int a[] = {52, 26, 54, 60,58,92,9,68,99,58};
    TS_ASSERT_DELTA(arrStdDev(a, 10), 25.3306, .0001);
  }
  
  void testStdDev2() {
    int a[] = {10,20,30,40};
    TS_ASSERT_DELTA(arrStdDev(a, 4), 11.1803, .0001);
  }
  void testStdDev3() {
    int a[] = {-2,200,56,-7, 12, 17};
    TS_ASSERT_DELTA(arrStdDev(a, 6), 71.7937, .0001);
  }
  void testStdDev4() {
    int a[] = {};
    TS_ASSERT_DELTA(arrStdDev(a, 0), 0, .0001);
  }
//PRIME
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

//NUM PRIMES
  void testNumPrimes1() {
    int a[] = {1,0, -3};
    TS_ASSERT_EQUALS(arrNumPrimes(a, 3), 0);
  }
  void testNumPrimes2() {
    int a[] = {3, 4, 5, 6, 7};
    TS_ASSERT_EQUALS(arrNumPrimes(a, 5), 3);
  }
  void testNumPrimes3() {
    int a[] = {17,21, 50, 70};
    TS_ASSERT_EQUALS(arrNumPrimes(a, 4), 1);
  }
  void testNumPrimes4() {
    int a[] = {1,0, -3, 4, 9, 10};
    TS_ASSERT_DIFFERS(arrNumPrimes(a, 6), 1);
  }
  void testNumPrimes5() {
    int a[] = {};
    TS_ASSERT_EQUALS(arrNumPrimes(a, 0), 0);
  }
  
//SET SIZE
  void testSetSize1() {
    int a[] = {1,1, 1, 2, 3, 4, 5};
    TS_ASSERT_EQUALS(arrSetSize(a, 7), 5);
  }
  void testSetSize2() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TS_ASSERT_EQUALS(arrSetSize(a, 10), 10);
  }
  void testSetSize3() {
    int a[] = {1,2, 3, 4, 5, 6, 1, 2, 3, 4, 5};
    TS_ASSERT_EQUALS(arrSetSize(a, 11), 6);
  }
  void testSetSize4() {
    int a[] = {};
    TS_ASSERT_EQUALS(arrSetSize(a, 0), 0);
  }
//NUM COUNT
  void testNumCount1() {
    int a[] = {2, 2, 2, 2, 2, 3, 4, 5};
    TS_ASSERT_EQUALS(arrNumCount(a, 8, 2), 5);
  }
  void testNumCount2() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TS_ASSERT_EQUALS(arrNumCount(a, 10, 5), 1);
  }
  void testNumCount3() {
    int a[] = {1,2, 3, 4, 4, 5, 6};
    TS_ASSERT_EQUALS(arrNumCount(a, 7, 4), 2);
  }
  void testNumCount4() {
    int a[] = {};
    TS_ASSERT_EQUALS(arrNumCount(a, 0, 7), 0);
  }
  void testNumCount5() {
    int a[] = {1, 2, 3};
    TS_ASSERT_DIFFERS(arrNumCount(a, 3, 3), 2);
  }
//NUM BETWEEN
  void testNumBetween1() {
    int a[] = {1, 2, 3, 4, 5, 6};
    TS_ASSERT_EQUALS(arrNumBetween(a, 6, 2, 5), 3);
  }
  void testNumBetween2() {
    int a[] = {1, 3, 2, 7, 5, 6, 9, 10, 4, 8};
    TS_ASSERT_EQUALS(arrNumBetween(a, 10, 3, 7), 4);
  } void testNumBetween3() {
    int a[] = {};
    TS_ASSERT_EQUALS(arrNumBetween(a, 6, 2, 5), 0);
  }
  void testNumBetween4() {
    int a[] = {1, 2, 3, 4, 5, 6};
    TS_ASSERT_DIFFERS(arrNumBetween(a, 6, 2, 5), 7);
  }

//REVERSE
  void testReverse1() {
    int a[] = {1,2,3,4};
    arrReverse(a,4);
    TS_ASSERT_EQUALS(a[0], 4);
    TS_ASSERT_EQUALS(a[1], 3);
    TS_ASSERT_EQUALS(a[2], 2);
    TS_ASSERT_EQUALS(a[3], 1);
  }
  
  void testReverse2() {
    int a[] = {1,2,3,4,5,6};
    arrReverse(a,6);
    TS_ASSERT_EQUALS(a[0], 6);
    TS_ASSERT_EQUALS(a[1], 5);
    TS_ASSERT_EQUALS(a[2], 4);
    TS_ASSERT_EQUALS(a[3], 3);
    TS_ASSERT_EQUALS(a[4], 2);
    TS_ASSERT_EQUALS(a[5], 1);
  }

  
  void testReverse3() {
    int a[] = {1,2,3,4,5,6,7};
    arrReverse(a,7);
    TS_ASSERT_EQUALS(a[0], 7);
    TS_ASSERT_EQUALS(a[1], 6);
    TS_ASSERT_EQUALS(a[2], 5);
    TS_ASSERT_EQUALS(a[3], 4);
    TS_ASSERT_EQUALS(a[4], 3);
    TS_ASSERT_EQUALS(a[5], 2);
    TS_ASSERT_EQUALS(a[6], 1);
  }

  void testReverse4() {
    int a[] = {10, 12, 14};
    arrReverse(a,3);
    TS_ASSERT_EQUALS(a[0], 14);
    TS_ASSERT_EQUALS(a[1], 12);
    TS_ASSERT_EQUALS(a[2], 10);
  }

  //FIND
  void testFind1() {
    int a[] = {1, 2, 3};
    TS_ASSERT_EQUALS(arrFind(a, 3, 3), 2);
  }
  void testFind2() {
    int a[] = {1, 2, 3};
    TS_ASSERT_EQUALS(arrFind(a, 3, 4, 1), -1);
  }
  void testFind3() {
    int a[] = {1, 2, 3, 4, 5};
    TS_ASSERT_EQUALS(arrFind(a, 5, 2, 0), 1);
  }
  void testFind4() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    TS_ASSERT_EQUALS(arrFind(a, 7, 4, 2), 3);
  }
  void testFind5() {
    int a[0] = {};
    TS_ASSERT_EQUALS(arrFind(a, 0, 4, 2), 0);
  }
  void testFind6() {
    int a[4] = {1, 2, 3, 4};
    TS_ASSERT_EQUALS(arrFind(a, 4, 1, 10),-1);
  }
  
  

};

#endif
