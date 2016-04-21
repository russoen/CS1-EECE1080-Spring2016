//You will need to prompt the user for the necessary information 
//to calculate the surface area and the volume of these shapes. 
//Please provide hand calculations to verify your program's output.  
//Surface Area =  [Base Area] +  12 × Perimeter × [slantHeight]
//Volume = (1/3) × [Base Area] × Height
// *height = top to bottom height
#include<iostream>
#include<cmath>
using namespace std;

class Pyramid{
  private:
    double baseArea; 
    double basePerimeter;
    double slantHeight;
    double pyrHeight;

  public:
  Pyramid(){
    baseArea = 0.0; 
    basePerimeter = 0.0;
    slantHeight = 0.0;
    pyrHeight = 0.0;
  }
//  Pyramid(){}
  
  //setters
  void setArea(double area){
    baseArea = area;
  }
  void setPerimeter(double perimeter){
    basePerimeter = perimeter;
  }
  void setSlant(double slant){
    slantHeight = slant;
  }
  void setHeight(double height){
    pyrHeight = height;
  }
  
  //getters
  double getSurfaceArea(){
  //Surface Area =  [Base Area] +  12 × Perimeter × [slantHeight]  
    return baseArea + (1./2.) * basePerimeter * slantHeight;
  }

  double getVolume(){
  //Volume = (1/3) × Base Area × Height
    return (1./3.) * baseArea * pyrHeight;
  }
};


int main(){
  Pyramid a;
  double area =0;
  double perimeter = 0;
  double sHeight = 0;
  double pHeight = 0;
  
  cout << "Enter base area: ";
  cin >> area;
  a.setArea(area);
  
  cout << "Enter base perimeter: ";
  cin >> perimeter;
  a.setPerimeter(perimeter);
  
  cout << "Enter slant height (side length): ";
  cin >> sHeight;
  a.setSlant(sHeight);
  
  cout << "Enter pyramid height: ";
  cin >> pHeight;
  a.setHeight(pHeight);
  
  cout << "Surface area = " << a.getSurfaceArea() << endl;
  cout << "Volume = " << a.getVolume() << endl;
}




