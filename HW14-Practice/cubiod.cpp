//You will need to prompt the user for the necessary information 
//to calculate the surface area and the volume of these shapes. 
//Please provide hand calculations to verify your program's output.  
//w = width, l = length, h = height
//Surface Area = 2wl + 2lh + 2hw
//Volume = lwh
#include<iostream>
#include<cmath>
using namespace std;

  double getSA(double width, double length, double height){
    return 2.0*width*length+2.0*length*height+2.0*height*width;
  }
  double getVolume(double width, double length, double height){
    return length*width*height;
  }


int main(){
  double w =0.0;
  double l = 0.0;
  double h = 0.0;
  cout << "Enter width: ";
  cin >> w;
  cout << "Enter length: ";
  cin >> l;
  cout << "Enter height: ";
  cin >> h;
  cout << "Surface Area = " << getSA(w, l, h) << endl;
  cout << "Volume = " << getVolume(w, l, h) << endl;
  return 0;
}
