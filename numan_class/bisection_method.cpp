#include <iostream>
#include <cmath>
using namespace std;
double function(double x);
int main(int argc, char* argv[]){
  int i,N;
  N = 100;
  double tolerance= 1.0e-5;
  double a,b,p,FA,FP,ran,err;
  a = 1.0,b=2.0;
  i=0;
  FA = function(a);
  while(i<N){
    p = a + (b-a)/2;
    FP =function(p);
    err = (p-err)/p;
    if (FP == 0 || ((b-a)/2)<tolerance){
      cout<<"This is the solution : "<<p;
      break;
    }
    i = i+1;
    if (FA*FP>0){
      a = p;
      FA = FP;
      cout<<"Value of interval ("<<a<<", "<<b<<")"<<"Function value "<<"( "<<FA<<" ,"<<FP<<")"<<". And the relative error is : "<<err<<endl;
    }
    else{
      b = p;
    }
    ran = p;
  }
  cout<<"After so many iteration , ans: x axis intersection or p value is "<<p<<" and f(p) value is "<<function(p)<<endl;


  return 0;
}
double function(double x){
  return ((x*x*x) + (4*x*x) - 10);
}
