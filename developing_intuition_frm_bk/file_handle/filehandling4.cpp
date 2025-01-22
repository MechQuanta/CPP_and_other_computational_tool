#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(int argc,char *argv[]){
  double x=234.45, y=-0.003234;
  ofstream write_file("setfscientificshowpos.dat");
  assert(write_file.is_open());
  write_file.setf(std::ios::scientific);
  write_file.setf(std::ios::showpos);
  write_file.precision(13);
  write_file<<x<<" "<<y<<endl;
  write_file.close();
  return 0;
}
