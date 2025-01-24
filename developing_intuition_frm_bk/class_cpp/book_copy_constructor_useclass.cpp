#include <iostream>
#include <cassert>
#include "book_copy_constructor.hpp"
using namespace std;
int main(int argc, char* argv[]){
  book instance1;
  instance1.author = "Sajid";
  instance1.publisher = "Springer";
  instance1.title = "Plasma physics combined with rl";
  instance1.review = true;
  instance1.setYearOfPublication(2024);
  book another_instance(instance1);
  cout<<"\n"<<endl;
  cout<<"Author name : "<<another_instance.author<<" ,publisher: "<<another_instance.publisher<<" ,title: "<<another_instance.title<<" ,review: "<<another_instance.review<<" ,year of publication: "<<another_instance.getYearOfPublication()<<endl;



  return 0;
}
