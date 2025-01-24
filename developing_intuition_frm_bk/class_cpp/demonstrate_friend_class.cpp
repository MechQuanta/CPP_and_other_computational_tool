#include <iostream>
#include "friend_class.hpp"
using namespace std;
mathematical::mathematical(){
  variable1 = 0;
  variable2 = 0;
}
mathematical::mathematical(double var1, double var2){
  variable1 = var1;
  variable2 = var2;
}
double mathematical::getMinimum() const{
  if(variable1<variable2){
    return variable1;
  }
  else{
    return variable2;
  }
}
double getMaximum(const mathematical& numers){
  if(numers.variable1<numers.variable2){
    return numers.variable2;
  }
  else{
    return numers.variable1;
  }
}
