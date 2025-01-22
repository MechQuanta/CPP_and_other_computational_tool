#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc , char *argv[]){
  double x[3],y[3];
  ifstream read_file("mechquanta.dat");
  assert(read_file.is_open());
  for (int i =0; i<3; i++){
    read_file>>x[i]>>y[i];
  }
  for (int i =0; i<3; i++){
    cout<<x[i]<<" "<<y[i]<<endl;
  }
  read_file.close();

}
