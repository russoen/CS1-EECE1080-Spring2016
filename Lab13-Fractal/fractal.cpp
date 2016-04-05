/*    @file fractal.cpp    
      @author <-- Fill in your name here -->
      @date <-- Fill this in -->

			@description 
*/
#include <iostream>
#include <stdlib.h>
#include <sstream>
// Use your myComplex class!
#include "myComplex.h"

// Import and setup the CImg library
#define cimg_display 0
#include "CImg.h"

using namespace std;


// Convenience function to set the red, green, and blue channels
// at a given pixel location in the image.
void setRGB(int x, int y, unsigned char red, unsigned char green, unsigned char blue, cil::CImg<unsigned char>& image){
  *(image.data(x,y,0,0)) = red;
  *(image.data(x,y,0,1)) = green;
  *(image.data(x,y,0,2)) = blue;
}

myComplex p(myComplex x){
  return (x*x*x*x*x*x*x*x*x*x*x*x) - (x*x*x*x*x*x) + (x*x*x*x*x) + (myComplex(5,0)*x*x*x*x) - myComplex(5,0) ;
}
myComplex prime(myComplex x){
  return (myComplex(12, 0)*x*x*x*x*x*x*x*x*x*x*x) - (myComplex(6,0)*x*x*x*x*x) + (myComplex(5,0)*x*x*x*x) + (myComplex(20, 0)*x*x*x);
}

int newton(myComplex zn){ 
  int count = 0;
  myComplex zn1;
  while(count < 500){
    zn1 = zn - ( p(zn)/prime(zn) );
    count++;
    if(abs(zn1.getMagnitude()-zn.getMagnitude()) < .0001 ){
      break;
    }
    zn = zn1;
  }
  return count;
}
  
int main(int argc, char* argv[]){
// We accept 3 command-line paramters, filename, x and y
  // If no paramters are given, it will save a 800x600 image 
  // to image.png
  
  string filename = "image.png";
  if(argc >= 2){
    filename = argv[1];
  }
  
  // Default Image size
  int width  = 1500;
  int height = 1000;
  
  if(argc >= 3){  // Width was given
    width = atoi(argv[2]);
  }
  if(argc >= 4){  // Height was given
    height = atoi(argv[3]);
  }
  
  // The image will be from -100 to +100 in both axes and scaled to
  // fit the requested image size.
  double urr = 100.0; // UpperRightReal (x)
  double uri = 100.0; // UpperRightImaginary (y)
  
  double llr = -100.0;
  double lli = -100.0;
 
  double dx = (urr-llr) / (double)width;
  double dy = (uri-lli) / (double)height;
  
  // Setup the image in CImg
  cil::CImg<unsigned char> image(width,height,1, 3, 255); 
  for(int x = 0; x < width; x++){
    for(int y = 0; y < height; y++){
      // Calculate where in the complex plane this point is
      double real = (double)x * dx + llr;
      double complex = (double)y * dy * -1 + uri;
      // Now real and complex will be x and y from -100 to +100
      
      // For this example, just do a fade.
      // There are 3 channels, R,G,B  which you can assign to.
      // Each channel takes a single byte 0-255
      myComplex z = myComplex(real, complex);
      setRGB(x,y,
             (int)newton(z) * newton(z) * 1, 
             (int)(newton(z) * 256 ) ,
             (int)newton(z) * 1000,
             image);
    }
  } 
  
  // save the image
  cout << "Saving: " << filename << " Width: " << width;
  cout << " Height: " << height << endl;
  // Saves the image
  image.save(filename.c_str());
  
  return 0;
}
