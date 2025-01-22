#include <iostream>

using namespace std;
double** AllocateMemoryForMatrix(int numrows,int numcols);
double** AllocateMemoryForMatrix2(double** matrix,int numrows,int numcols);
void ClearMemoryMatrix(int numrows,double** matrix);
int main(int argc, char *argv[]){

  double** matrix_without_func;
  int numrows=2;
  int numcols=2;
  double** matrix = AllocateMemoryForMatrix2(matrix_without_func,numrows=2,numcols=2);
  matrix[0][0]=1,matrix[0][1]=2;
  matrix[1][0]=2,matrix[1][1]=3;
  for (int i=0; i<2; i++){
    for (int j=0; j<2; j++){
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }


  return 0;
}
double** AllocateMemoryForMatrix(int numrows, int numcols){
  double** matrix_arb;
  matrix_arb = new double* [numrows];
  for (int i=0; i<numcols; i++){
    matrix_arb[i] = new double[numcols];
  }
  return matrix_arb;
}
double** AllocateMemoryForMatrix2(double** matrix,int numrows,int numcols){
  matrix = new double* [numrows];

  for (int i=0; i<numrows; i++){
    matrix[i] = new double[numcols];
  }
  return matrix;
}
void ClearMemoryMatrix(int numrows, double** matrix){
  for (int i=0; i<numrows; i++){
    delete[] matrix[i];
  }
  delete matrix;
}
