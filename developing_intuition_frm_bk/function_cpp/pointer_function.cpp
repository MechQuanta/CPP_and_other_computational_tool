#include <iostream>
#include <cmath>
using namespace std;

double SolveNewton(double (*p_func) (double),double (*p_func_prime) (double),double x);
double func1(double x);
double func1p(double x);
double func2(double x);
double func2p(double x);

int main(int argc,char* argv[]){
  cout<<"solution of newton rhapson solver with initial x = 1 and function sqrt(x) - 10.0 is "<<SolveNewton(func1,func1p,1.0)<<endl;
  cout<<"solution of newton rhapson solver with initial x = 1 and function x*x*x - 10.0 is "<<SolveNewton(func2,func2p,1.0)<<endl;


}
double SolveNewton(double (*p_func) (double),double (*p_func_prime) (double),double x){
  double step;
  do{
    step = (*p_func)(x)/(*p_func_prime)(x);
    x = x-step;
    cout<<"x : "<<x<<" ";
    cout<<"error : "<<step<<endl;
  }while(fabs(step)>1.0e-6);
  return x;
}
double func1(double x){
  return sqrt(x) - 10.0;
}
double func1p(double x){
  return 1/(2*sqrt(x));
}
double func2(double x){
  return x*x*x - 10;
}
double func2p(double x){
  return 3*x*x;
}
