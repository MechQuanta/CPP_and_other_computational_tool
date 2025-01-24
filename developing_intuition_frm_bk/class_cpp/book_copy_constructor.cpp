#include <iostream>
#include "book_copy_constructor.hpp"
#include <cassert>
using namespace std;

book::book(){
  author = "not given any name";
  publisher = "not given any publisher to publish";
  title = "Not given any title";
  review = false;
  price = 0;
  //setYearOfPublication(0);
}
book::book(const book& instance_book){
  author = instance_book.author;
  publisher = instance_book.publisher;
  title = instance_book.title;
  review = instance_book.review;
  price = instance_book.price;
  //setYearOfPublication(instance_book.getYearOfPublication());
  mYearOfPublication = instance_book.getYearOfPublication();
}
book::book(string book_title){
  title = book_title;
}
void book::setYearOfPublication(int Year){
  assert((Year>1900) && (Year<2050));
  mYearOfPublication = Year;
}
int book::getYearOfPublication() const{
  return mYearOfPublication;
}
