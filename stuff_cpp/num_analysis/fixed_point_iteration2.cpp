#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
float func(float x);
int main(int argc,char* argv[]){
  float p0,p,tol;
  ofstream file_writer("fixedpoint_2ndfunctiofor_test.out");
  int i,N0;
  i=0;
  cout<<"N0: ";
  cin>>N0;
  cout<<"Initial guess: ";
  cin>>p0;
  cout<<"Tolerance : ";
  cin>>tol;
  file_writer<<i<<"\t"<<p0<<endl;
  while(i<=N0){
    p = func(p0);
    if(abs(p-p0)<tol){
      cout<<"This is my output: "<<p;
      break;
    }
    i = i + 1;
    p0 = p;
  }
  cout<<"After iteration, the solution is : "<<p;

  return 0;
}
float func(float x){
  return sqrt((10/x)-4*x);
}
