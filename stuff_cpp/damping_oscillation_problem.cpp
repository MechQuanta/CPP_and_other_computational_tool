#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
int main(int argc,char* argv[]){
  //d/dt[x; v] = [0 1; -2 -3] [x; v] and the differential equation is x''+3x'+2x = 0;
  //define matrix;
  double A[2][2];
  A[0][0]=0 ,A[0][1]=1;
  A[1][0]=-2,A[1][1]=-3;
  //initialize [x; v] with random number;
  vector<double> x0 = {2,-3};
  //my formulation will be x_k+1 = x_k + A*x_k*dt;
  //initialize time with size 1000 with 0 inside;
  vector<double> t(1001,0.0);
  vector<vector<double>> xF(1001,vector<double>(2.0,0.0));
  double dt = 0.001;
  double temp;
  //for writing output to a dat file , we will create a instance of ofstream class;
  ofstream write_output("damping_diffeq.dat");

  for (int i=1; i<=1000; i++){
    vector<double> x_new(2.0,0.0);
    t[i] = i*dt;
    for (int j=0; j<2; j++){
      temp = 0;
      for (int k=0; k<2; k++){
        temp += A[j][k]*x0[k]*dt;
      }
      x_new[j] = x0[j] + temp;
      xF[i][j] = x_new[j];
    }
    x0 = x_new;

    write_output<<i<<"|"<<t[i];
    for (int j=0; j<2; j++){
      write_output<<"|"<<xF[i][j];
    }
    write_output<<endl;
  }

  write_output.close();
  return 0;
}
