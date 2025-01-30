#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
float func(float x);
int main(int argc,char* argv[]){
  float p0,p,tol;
  int i,N0;
  i=0;
  ofstream filee("fixedpointiteration_work_but_not_efficient.out");
  cout<<"initial guess: ";
  cin>>p0;
  p = p0;
  cout<<"How many Iteration: ";
  cin>>N0;
  cout<<"Tolerance: ";
  cin>>tol;
  filee<<"i"<<"\t"<<"p"<<"\t"<<"|p-p0|"<<endl;
  //filee<<i<<"\t"<<p0<<"\t"<<abs(p0-p)<<endl;
  while(i<=N0){
    p = func(p0);
    filee<<i<<"\t"<<p0<<"\t"<<abs(p0-p)<<endl;
    if (abs(p-p0)<tol){
      cout<<"This is output solution: "<<p;
      break;
    }
    i = i + 1;
    p0 = p;
  }
  cout<<"Ultimate output: "<<p<<endl;
  return 0;
}
float func(float x){
  return (0.5*sqrt(10-x*x*x));
}
