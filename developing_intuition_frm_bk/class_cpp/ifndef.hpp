#ifndef BOOKHEADERDEF
#define BOOKHEADERDEF

#include <string>

class Book{
public:
  std::string author,publisher,title;
  int price;
  void setYearOfPublication(int Year);
  int getYearOfPublication() const;
private:
  int mYearOfPublication;
};

#endif
