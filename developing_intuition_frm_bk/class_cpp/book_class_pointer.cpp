#include <iostream>
#include "book_copy_constructor.hpp"
using namespace std;
int main(int argc, char* argv[]){
  book* p_book = new book;
  (*p_book).author = "sajid";
  p_book->title = "Deep reinforcement learning";
  cout<<(*p_book).author<<p_book->title<<endl;

  return 0;
}
