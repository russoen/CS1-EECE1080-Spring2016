#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;


// Some CONSTANTS you may find useful.
const double PI = atan(1.0)*4;
const double FEET_PER_MILE =  5280;
const double INCHES_PER_FOOT =  12;
const double INCHES_PER_MILE = FEET_PER_MILE*INCHES_PER_FOOT;
const double MINUTES_PER_HOUR = 60;
const double SECONDS_PER_MINUTE = 60;
const double DEFAULT_TIRE_SIZE = 15;
const double inf = std::numeric_limits<double>::infinity();

class Wheel {
public: 
  // Set the speed and rpms to zero and the radius to DEFAULT_TIRE_SIZE
  Wheel(){
  radius = DEFAULT_TIRE_SIZE;
  speed = 0.0;
  rpm = 0.0;
  setSpeed(speed);
  setRPM(radius, speed);
  }

  // Set the speed and rpms to zero and the radius to in_radius
  Wheel(double in_radius){
  radius = in_radius;
  speed = 0.0;
  rpm = 0.0;
  }

  // set the wheel radius and a vehicle speed in MPH.
  // Calculate the RPM based on speed and radius
  Wheel(double in_radius, double in_speed){
  radius = in_radius;
  speed = in_speed;
  rpm = (speed/60)/(2*PI*(radius/12/5280));
  }

  // Set the RPM and update the speed 
  // We have count revolution in a certain interval of time 
  // seconds
  void setRPM(double in_revolutions, double in_time){
    if (in_time < 0){
      rpm = 0;
    }else{
      rpm = in_revolutions/(in_time/60);
      speed = rpm*(2* PI * (radius/12/5280))*60;
    }
  }

  // Set a new speed and update the RPM
  void setSpeed(double in_speed){
    speed = in_speed;
    rpm = (speed/60)/(2*PI*(radius/12/5280));
  }
  

  double getRadius(){
    if(radius < 0 || speed < 0){
      return 0.0;
    }
    return radius;
  }
  double getDiameter(){
    if(radius < 0 || speed < 0){
      return 0.0;
    }
    return radius * 2;
  }
  double getCircumference(){
    if(radius < 0 || speed < 0){
      return 0.0;
    }
    return 2 * PI * radius;
  }
  double getSurfaceArea(){
    if(radius < 0 || speed < 0){
      return 0.0;
    }
    return PI * radius * radius;
  }
  double getSpeed(){
    if(radius < 0 || speed < 0){
      return 0.0;
    }
    if (speed == inf || speed == -inf){
      return 0.0;
    }
	  return speed;
  }
  double getRPM(){
    if (rpm == inf || rpm == -inf){
      return 0.0;
    }
  	return rpm;
  }

  // Display the Wheel Parameters
  void displayParameters(){
    cout << "Wheel Radius: " << radius << endl;
    cout << "Speed: " << speed << " MPH" << endl;
    cout << "Wheel Circumference: " << getCircumference() << " inches" << endl;
    cout << "Wheel Spin Rate: " << rpm << " RPM" << endl;
  }

private:
  double radius;   // radius inches
  double speed;   // MPH
  double rpm;   // RPM
};

