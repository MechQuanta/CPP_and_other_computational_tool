#include <iostream>
#include <cmath>
using namespace std;

void Iteration_Technique(double &x, int k,int numiter,double tolerance);

int main(int argc, char* argv[]){
  double x;
  double k;
  int max_num_iter;
  double tolerance = 1.0e-6;
  x = 1.0;
  k = 12.0;
  max_num_iter = 100;

  Iteration_Technique(x,k,max_num_iter,tolerance);

  cout<<"final x: "<<x<<endl;


  return 0;
}
void Iteration_Technique(double &x, int k,int numiter,double tolerance){
  int i=0;
  double residual;
  residual = x*x*x -k;
  while((fabs(residual)>tolerance)){
    if(i<numiter){
      x = x - ((x*x*x - k)/(3*x*x));
      residual = x*x*x -k;
      cout<<"x value:- "<<x<<" .";
      cout<<"x^3 - k : "<<residual<<endl;
      i++;
    }
  }
}
