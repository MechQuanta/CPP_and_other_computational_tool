#include <iostream>
#include <cmath>
using namespace std;
void CalculateRealAndImaginaryPart(double r, double theta,double* real_value,double* imaginary_value);
int main(int argc, char* argv[]){
  double r = 2.0;
  double pi = 2 * acos(0.0);
  double theta = pi;
  double x,y;
  CalculateRealAndImaginaryPart(r,theta,&x,&y);
  cout<<"Real Part = "<<x<<"Imaginary Part = "<<y<<endl;

  return 0;
}
void CalculateRealAndImaginaryPart(double r, double theta,double* real_value,double* imaginary_value){
  *real_value = r*cos(theta);
  *imaginary_value = r*sin(theta);
}
