#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

float func(float x){
  return (x*x-2);
}
int main(int argc, char const *argv[]) {
  float a,b,p,tol,p0;
  int N0,i;
  cout<<"Give the left boundary(a): ";
  cin>>a;
  cout<<"Give the right boundary(b): ";
  cin>>b;
  cout<<"give the in between value(p): ";
  cin>>p;
  cout<<"Total number: ";
  cin>>N0;
  cout<<"give tolerance: ";
  cin>>tol;
  ofstream filew("burdenp56.dat");
  filew<<"iteration"<<"\t"<<"p=g(p)"<<"\t"<<"absolute err"<<endl;
  //p0 = func(p);
  i=0;
  while(true){
    p0 = func(p);
    if(abs(p-p0)<tol){
      filew<<i<<"\t"<<p0<<"\t"<<abs(p-p0)<<endl;
      break;
    }
    else{
      filew<<i<<"\t"<<p0<<"\t"<<abs(p-p0)<<endl;
      p=p0;
    }
    }
    i++;
  return 0;
}
