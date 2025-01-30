#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
float func(float x);

int main(int argc,char* argv[]){
  //variable declaration;
  float p0,tol,p;
  //file instance declaration;
  ofstream write_output("fixed_point_iteration_not_very_efficient.out");
  int i,N0;
  i=0;
  cout<<"Plug the value of iteration number you want: ";
  cin>>N0;
  cout<<"Plug the initial guess: ";
  cin>>p0;
  cout<<"The tolerance value you want: ";
  cin>>tol;
  write_output<<i<<"\t"<<p0<<endl;
  while(i<=N0){
    p = func(p0);
    write_output<<i<<"\t"<<p<<endl;
    if (abs(p - p0)<tol){
      cout<<"My error has less than tolerance value. So, i can conclude my solution is: "<<p<<endl;
      break;
    }
    i = i+1;
    p0 = p;
  }
  cout<<"After so many iteration my final solution is : "<<p<<endl;


  return 0;
}
float func(float x){
  return (x-x*x*x-4*x*x+10);
}
