#include <iostream>
using namespace std;
const int N = 3;
const int M = 2;
int main(){
  int **a,**b,**c;
  int i,j,k;
  a = new int *[M+1];
  b = new int *[N+1];
  c  = new int *[M+1];
  for (i=1; i<=M; i++){
    a[i] = new int[N+1];
  }
  for (i=1; i<=N; i++){
    b[i] = new int[M+1];
  }
  for (i=1; i<=M; i++){
    c[i] = new int[M+1];
  }
  a[1][1]=1; a[1][2] = 2; a[1][3] = 3;
  a[2][1]=4; a[2][2]= 5; a[2][3] = 6;
  cout<<"Matrix of A: "<<endl;
  for (i = 1; i<=M; i++){
    cout<<"\n"<<endl;
    for (j = 1; j<=N; j++){
      cout<<a[i][j]<<' ';
    }
  }
  cout<<endl;
  b[1][1] = 7; b[1][2] = 10;
  b[2][1] = 8; b[2][2] = 11;
  b[3][1] = 9; b[3][2] = 12;

  cout<<"Matrix of B: "<<endl;
  for (i=1; i<=N; i++){
    cout<<"\n"<<endl;
    for (j=1; j<=M; j++){
      cout<<b[i][j]<<" ";
    }
  }
  cout<<endl;


  for (i = 1; i <= M; i++) {
       for (j = 1; j <= M; j++) {
           c[i][j] = 0; // Initialize c[i][j] to 0
           for (k = 1; k <= N; k++) {
               c[i][j] += a[i][k] * b[k][j];
           }
       }
   }
  cout<<"Matrix of C: "<<endl;
  for (i=1; i<=M; i++){
    cout<<"\n"<<endl;
    for (j=1; j<=M; j++){
      cout<<c[i][j]<<" ";
    }
  }
  cout<<endl;



  for (i = 1; i<=M; i++){
    delete[] a[i];
  }

  delete[] a;
  for (i = 1; i<=N; i++){
    delete[] b[i];
  }
  delete[] b;

  for (i=1; i<=M; i++){
    delete[] c[i];
  }

  delete[] c;

  return 0;
}
