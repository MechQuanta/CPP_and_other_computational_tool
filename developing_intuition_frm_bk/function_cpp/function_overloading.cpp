#include <iostream>
#include <cmath>
using namespace std;
void  multiply(double scaler,double* u, double* v, int n);
void multiply(double scaler, double** A,double** B, int n);

int main(int argc,char* argv[]){
  int n = 2;
  double scaler = 2.0;
  double mat_scal = 3.0;
  double* u = new double[n];
  double* v = new double[n];
  double** A = new double* [n];
  double** B = new double* [n];
  for (int i=0; i<n; i++){
    A[i] = new double[n];
    B[i] = new double[n];
  }
  u[0] = 1.0,u[1] = 2.0;
  A[0][0] = 1.0, A[0][1] = 2.0;
  A[1][0] = 3.0, A[1][1] = 4.0;
  multiply(scaler,u,v,n);
  multiply(mat_scal,A,B,n);
  cout<<" u : ";
  for (int i=0; i<n; i++){
    cout<<v[i]<<" ";
  }
  cout<<"\n"<<endl;
  cout<<"B : "<<endl;
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      cout<<B[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;
}
void multiply(double scaler, double* u,double* v, int n){
  for (int i=0; i<n; i++){
    v[i] = scaler*u[i];
  }
}
void multiply(double scaler,double** A, double** B, int n){
  for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      B[i][j] = scaler*A[i][j];
    }
  }
}
