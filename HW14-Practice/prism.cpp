//You will need to prompt the user for the necessary information 
//to calculate the surface area and the volume of these shapes. 
//Please provide hand calculations to verify your program's output.  
//Surface Area = 2 × Base Area +  Base Perimeter × Length
//Volume = Base Area × Length
#include <iostream>
#include <cmath>
using namespace std;

class Prism{
private:
double baseArea;
double basePerimeter;
double length;
public:
Prism(){
  baseArea = 0.0;
  basePerimeter = 0.0;
  length = 0.0;
}
//setters
void setArea(double a){
  baseArea = a;
}
void setPerimeter(double p){
  basePerimeter = p;
}
void setLength(double l){
  length = l;
}

//getters
double getSA(){
  return 2.0*baseArea+basePerimeter*length;
}
double getVolume(){
  return baseArea*length;
}
};

int main(){
  Prism b;
  double a = 0.0;
  double p = 0.0;
  double l = 0.0;
  
  cout << "Enter base area: ";
  cin >> a;
  b.setArea(a);
  
  cout << "Enter base perimeter: ";
  cin >> p;
  b.setPerimeter(p);
  
  cout << "Enter length: ";
  cin >> l;
  b.setLength(l);
  
  cout << "Surface area = " << b.getSA() << endl;
  cout << "Volume = " << b.getVolume() << endl;
  return 0;
}
