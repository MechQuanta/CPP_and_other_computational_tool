#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
float func(float x);
int main(int argc,char* argv[]){
  float p0,p,tol;
  int i,N0;
  i=0;
  cout<<"Initial guess: ";
  cin>>p0;
  cout<<"Number: ";
  cin>>N0;
  cout<<"Tolerance: ";
  cin>>tol;
  ofstream filee("fileiterationtechnique_quite_good_compareto_theprvs_one.out");
  filee<<"i"<<"\t"<<"p"<<"\t"<<"p-p0"<<endl;
  while(i<=N0){
    p = func(p0);
    filee<<i<<"\t"<<p<<"\t"<<abs(p-p0)<<endl;
    if (abs(p-p0)<tol){
      cout<<"This is my solution: "<<p<<endl;
      break;
    }
    i = i + 1;
    p0 = p;
  }
  cout<<"Final solution: "<<p<<endl;


  return 0;
}
float func(float x){
  return (sqrt(10/(4+x)));
}
