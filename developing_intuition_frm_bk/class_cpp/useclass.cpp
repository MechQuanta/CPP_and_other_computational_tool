#include <iostream>
#include "ifndef.hpp"
using namespace std;

int main(int argc,char* argv[]){
  Book publishedbook;
  publishedbook.author = "Sajid Khan";
  publishedbook.publisher = "Springer";
  publishedbook.title = "Plasma Control using deep reinforcement learning";
  publishedbook.price = 300;
  publishedbook.setYearOfPublication(2024);
  cout<<"Name of Author : "<<  publishedbook.author<<" .Pulisher of this book: "<<publishedbook.publisher<<" .Books title: "<<publishedbook.title<<" .Price of this book : "<<publishedbook.price<<" .Year of Publication : "<<publishedbook.getYearOfPublication();
}
