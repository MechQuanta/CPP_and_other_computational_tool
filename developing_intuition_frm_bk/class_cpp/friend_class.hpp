#ifndef FREINDCLASS
#define FRIENDCLASS
#include <iostream>
using namespace std;

class mathematical{
  public:
    mathematical();
    mathematical(double var1 , double var2);
    double getMinimum() const;
    friend double getMaximum(const mathematical& numers);
  private:
    double variable1;
    double variable2;
};
#endif
