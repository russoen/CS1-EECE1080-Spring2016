// Author: Fill name in here
// Source File: lines.cpp
// Description: Implements a line class.  Provide two points on the 
// line and this class can tell you the slope, intercept, and if two
// lines are paralell, perpendicular, and their intersection point.

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
using namespace std;

const double DDIFF = 0.0001;
const double inf = std::numeric_limits<double>::infinity();

struct point_t{
  double x_coord, y_coord;
};

class Line{
  private:
    point_t a, b;
    
  public:
  
  // Default constructor makes 2 points at 0,0
  Line(){
    point_t zero;
    zero.x_coord = 0.0;
    zero.y_coord = 0.0;
    setPoints(zero, zero);
  }
  
  // Take two points to define a line.
  Line(point_t a_temp, point_t b_temp){
    setPoints(a_temp, b_temp);
  }

  // Assign the given points to this line
  void setPoints(point_t a_temp, point_t b_temp){
    a = a_temp;
    b = b_temp;  
  }
  
  // Return the first point of the line
  point_t getFirstPoint(){
    point_t ret;
    ret.x_coord = a.x_coord;
    ret.y_coord = a.y_coord;
    return ret;
  }
  
  // Return the second point of the line
  point_t getSecondPoint(){
    point_t ret;
    ret.x_coord = b.x_coord;
    ret.y_coord = b.y_coord;
    return ret;
  }
  
  // Given the line, what is the slope?  Return inf (constant above) if
  // the the line is vertical (no x difference).
  double getSlope(){
    double slope = 0.;
    slope = (b.y_coord - a.y_coord)/(b.x_coord - a.x_coord);
    if((b.x_coord - a.x_coord) == 0){
      return inf;
    }
      return slope;
    }
  
  // Returns the intercept (the y location where the line intercepts the y axis).
  // If the line is vertical, return 0;
  double getIntercept(){
    double intercept = a.y_coord - getSlope()*a.x_coord;
      if(getSlope() == inf){
        intercept = 0;
      }
    return intercept;
  }
  
  // Returns a string containing point1 point2
  string getLineInfo(){
    stringstream temp;
    temp << a.x_coord << "," << a.y_coord << " " << b.x_coord << "," << b.y_coord;
    return temp.str();
  }

  // Returns the length of the line between the two points
  double getLength(){
    double length = sqrt ((b.x_coord-a.x_coord)*(b.x_coord-a.x_coord) + (b.y_coord-a.y_coord)*(b.y_coord-a.y_coord));
    return length;
  }
  
  // Returns true if the line is horizontal  
  bool isHorizontal(){
    if(a.y_coord == b.y_coord) return true;
    return false;
  }
  
  // Returns true if the line is vertical  
  bool isVertical(){
    if(a.x_coord == b.x_coord) return true;
    return false;
  }

  // Return the distance between two lines.  If they intersect, return 0.0.
  // Return value should always be positive.
  double getDistance(Line line2){
  double distance = 0.0;
    if(abs(getSlope() - line2.getSlope()) < DDIFF){
      distance = (fabs(getIntercept() - line2.getIntercept())/sqrt(getSlope()*getSlope() +1));
    }else if(isVertical() && line2.isVertical()){
      distance = fabs (a.x_coord-line2.a.x_coord); 
    }else{
      distance = 0.0;
    }
    return distance;
  }


  // Return true if the two lines are parallel.  Be sure to return the 
  // correct result if they are both vertical!
  bool isParallel(Line line2){
    if(getSlope() != line2.getSlope()){
      return false;
    }else if (getSlope() == inf && line2.getSlope() == inf) return true;
    return true;
      
  }
  
  // Return true if the two lines are perpendicular.  Be sure to return the
  // correct result if they one is vertical.
  bool isPerpendicular(Line line2){
    if((getSlope() == (-1/line2.getSlope()) )|| (line2.getSlope() == (-1/getSlope())) ){
      return true;
    }
    return false;
  }



};

