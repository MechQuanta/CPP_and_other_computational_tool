#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
  double x[100],y[100];
  ifstream reading("mechquanta.dat");
  assert(reading.is_open());
  int i = 0;
  while(!reading.eof()){
    reading>> x[i] >> y[i];
    i++;
  }
/*   cout<<sizeof(x)<<endl;
  cout<<sizeof(x[0])<<endl;
  cout<<size(x)/sizeof(x[0])<<endl;
  for (int j=0; j<(size(x)/sizeof(x[0])); j++){
    cout<<x[j]<<endl;
  }
*/
  for (int j = 0; j<3; j++){
    cout<<x[j]<<y[j]<<endl;
  }
  reading.clear();
  reading.seekg(std::ios::beg);
  assert(reading.is_open());
  int k = 0;
  while(!reading.eof()){
    reading>> x[i] >> y[i];
    k++;
  }
  for (int j = 0; j<3; j++){
    cout<<x[j]<<y[j]<<endl;
  }
  reading.close();
  return 0;
}
