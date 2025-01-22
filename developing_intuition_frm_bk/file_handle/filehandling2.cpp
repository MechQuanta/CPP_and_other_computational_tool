#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
  double x[3] = {1.556432,2.6776543,4.4345654};
  ofstream write_output("data.dat");
  assert(write_output.is_open());
  write_output.precision(5);
  for (int i=0; i<3; i++){
    write_output<<x[i]<<endl;
  }
  write_output.precision(10);
  write_output<<"\n"<<endl;
  for (int i=0; i<3; i++){
    write_output<<x[i]<<endl;
  }
  write_output.precision(15);
  write_output<<"\n"<<endl;
  for (int i=0; i<3; i++){
    write_output<<x[i]<<endl;
  }
  write_output.close();

  return 0;
}
