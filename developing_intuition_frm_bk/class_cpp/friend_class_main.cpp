#include <iostream>
#include "friend_class.hpp"
using namespace std;
int main(int argc, char* argv[]){
  mathematical instances1(1.0,2.0);
  cout<<"Minimum value between 1.0 and 2.0 is "<<instances1.getMinimum()<<". And maximum value between is "<<getMaximum(instances1)<<endl;
}
