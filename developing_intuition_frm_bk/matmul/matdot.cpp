#include <iostream>
using namespace std;
const int N = 3;
const int M = 3;
int main()
{
  int **q;
  q = new int *[M+1];
  for (int i=0; i<=N; i++){
    q[i] = new int[N+1];
  }
  int w = 0;
  for (int i=0; i<=M; i++){
    for (int j=0; j<=N; j++){
      q[i][j] = w+i+j;
    }
  }
  cout<<"matrix values : "<<endl;
  for (int i=0; i<=M; i++){
    for (int j=0; j<=N; j++){
      cout<<q[i][j]<<endl;
    }
  }
cout<<endl;

for (int i = 0; i<=M; i++){
  delete[] q[i];
}
delete[] q;
  return 0;
}
