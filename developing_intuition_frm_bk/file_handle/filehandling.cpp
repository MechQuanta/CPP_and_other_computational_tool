#include <cassert>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
  double x[3] = {1.0,2.0,3.0};
  for (int i=0; i<3; i++){
    cout<<x[i]<<" "<<endl;
  }
  double y[3] = {2.0,3.0,4.0};
  ofstream write_output("mechquanta.dat");
  assert(write_output.is_open());
  write_output<<"x"<<"   "<<"y"<<"\n"<<endl;
  for (int i = 0; i<3; i++){

    write_output<<x[i]<<"   "<<y[i]<<endl;
  }
  // for appending data for already created file and has data on it , we will use std::ofstream write_output("Output.dat", std::ios::app); this command

  write_output.close();
  return 0;
}
