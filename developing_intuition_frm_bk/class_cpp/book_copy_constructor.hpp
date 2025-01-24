#ifndef BOOKHEADREF
#define BOOKHEADREF
#include <iostream>
using namespace std;

class book{
  public:
    book();
    book(const book& instance_book);
    book(string book_title);
    string author,publisher,title;
    bool review;
    int price;
    void setYearOfPublication(int Year);
    int getYearOfPublication() const;
  private:
    int mYearOfPublication;

};
#endif
