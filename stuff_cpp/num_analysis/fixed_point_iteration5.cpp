#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
float func(float x);
float funcp(float x);
int main(int argc,char* argv[]){
  float p0,p,tol;
  int i,N0;
  i=0;
  cout<<"Initial guess: ";
  cin>>p0;
  cout<<"Number of iteration: ";
  cin>>N0;
  cout<<"tolerance";
  cin>>tol;
  ofstream fileee("most_efficient_method.out");
  fileee<<"i"<<"\t"<<"p"<<"\t"<<"p-p0"<<endl;
  while(i<=N0){
    p = func(p0);
    fileee<<i<<"\t"<<p<<"\t"<<abs(p-p0)<<endl;
    if (abs(p-p0)<tol){
      cout<<"The solution: "<<p<<endl;
      break;
    }
    i = i + 1;
    p0 = p;
  }
  cout<<"The solution is thus: "<<p<<endl;
  return 0;
}
float func(float x){
  return (x - ((x*x*x+4*x*x-10)/funcp(x)));
}
float funcp(float x){
  return (3*x*x+8*x);
}
