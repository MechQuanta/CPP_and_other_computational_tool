#include <cassert>
#include "ifndef.hpp"

void Book::setYearOfPublication(int Year){
  assert((Year>1440) && (Year<2040));
  mYearOfPublication = Year;
}
int Book::getYearOfPublication() const{
  return mYearOfPublication;
}
