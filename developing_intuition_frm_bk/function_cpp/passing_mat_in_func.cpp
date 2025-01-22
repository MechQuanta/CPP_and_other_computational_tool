#include <iostream>
#include <cmath>
using namespace std;
void modify_matrixandarrval_in_func(double** A, double* B);
int main(int argc, char* argv[]){
  double** mat = new double* [3];
  for (int i=0; i<3; i++){
    mat[i] = new double[3];
  }
  double* arr = new double[3];
  mat[0][0] = 1.0,mat[0][1] = 2.0,mat[0][2] = 3.0;
  mat[1][0]= 4.0, mat[1][1] = 5.0, mat[1][2] = 6.0;
  mat[2][0]= 7.0, mat[2][1] = 8.0, mat[2][2] = 9.0;
  arr[0]=10.0,arr[1]=11.0,arr[2]=12.0;
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"\n"<<endl;
  for (int i=0; i<3; i++){
    cout<<arr[i]<<" ";
  }
  cout<<"\n"<<endl;
  modify_matrixandarrval_in_func(mat,arr);
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"\n"<<endl;
  for (int i=0; i<3; i++){
    cout<<arr[i]<<" ";
  }
  for (int i=0; i<3; i++){
    delete[] mat[i];
  }
  delete mat;
  delete[] arr;
  return 0;
}
void modify_matrixandarrval_in_func(double** A , double* B){
  A[0][1] = 555.0;
  B[2] = 12222.0;
}
