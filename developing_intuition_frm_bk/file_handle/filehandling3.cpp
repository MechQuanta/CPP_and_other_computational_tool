#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]){
  ofstream writing("writing_good.dat");
  assert(writing.is_open());
  for (int i=0; i<100; i++){
    for (int j=0; j<100; j++){
      writing<<j<<" ";
      assert(writing.good());
    }
    writing<<"\n";
  }
  writing.close();
  return 0;
}
