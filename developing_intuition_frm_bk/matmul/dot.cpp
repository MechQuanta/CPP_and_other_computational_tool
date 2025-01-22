#include <iostream>
using namespace std;
const int N = 3;
int main()
{
  int *v,*u,*w;
  int i;
  v = new int[N+1];
  v[1] =1; v[2] = 2; v[3] = 3;
  cout<<"Vector v: "<<endl;
  for (i=1; i<=N; i++){
    cout<<v[i]<<" ";
  }
  cout<<endl;
  u = new int[N+1];
  u[1] = 2; u[2] = 3; u[3] = 4;
  cout<<"Vector of u: "<<endl;
  for (i=1; i<=N; i++){
    cout<<u[i]<<endl;
  }
  cout<<endl;
  w = new int[N+1];
  for (i=1; i<=N; i++){
    w[i] += v[i]*u[i];
  }
  cout<<"The result of dot product v.u is : "<<endl;

  for (i=1; i<=N; i++){
    cout<<w[i]<<endl;
  }
  cout<<endl;
  delete[] u,v,w;

  return 0;
}
