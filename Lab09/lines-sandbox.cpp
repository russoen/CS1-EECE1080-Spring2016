#include <iostream>

#include "lines.cpp"
using namespace std;

int main(){

  // Sandbox to play with your Line class
  
  // Some examples...
  
  // Create a line on the x axis
  point_t x1;
  x1.x_coord = 0.0;
  x1.y_coord = 1.0;
  
  point_t x2;
  x2.x_coord = 0.0;
  x2.y_coord = 1.0;
  
  Line xaxis(x1, x2);
  
  // Print some stats
  /*cout << "Info: " << xaxis.getLineInfo() << endl;
  cout << "Slope: " << xaxis.getSlope() << endl;
  cout << "Length: " << xaxis.getLength() << endl;
  cout << "Horizontal?: " << xaxis.isHorizontal() << endl;
  cout << "Vertical?: " << xaxis.isVertical() << endl;*/

  // Create a second line
  point_t x12;
    x12.y_coord = 0.0;
    x12.x_coord = 0.1;
  point_t x22;
    x22.y_coord = 0.0;
    x22.x_coord = 0.1;
  
  Line xaxis2(x12, x22);
  
  // Print some stats.
  cout << "1st line Horizantal?: " << xaxis.isHorizontal() << endl;
  cout << "2nd line Horizantal?: " << xaxis2.isHorizontal() << endl;
  cout << "1st line Verticle?: " << xaxis.isVertical() << endl;
  cout << "2nd line Verticle?: " << xaxis2.isVertical() << endl;
  cout << "1st line Slope: " << xaxis.getSlope() << endl;
  cout << "2nd Slope: " << xaxis2.getSlope() << endl;
  cout << "Parallel?: " << xaxis.isParallel(xaxis2) << endl;
  cout << "line 2 b.x: " << x22.x_coord << " b.x:" << x2.x_coord << endl;
  cout << "Distance: " << xaxis.getDistance(xaxis2) << endl;
  cout << "a.x:" << x1.x_coord << " a.y:" << x1.y_coord << "b.x: " << x2.x_coord << " b.y: " << x2.y_coord << endl;
  cout << "2a.x:" << x12.x_coord << " 2a.y:" << x12.y_coord << " 2b.x: " << x22.x_coord << " 2b.y: " << x22.y_coord << endl;

  return 0;
}
