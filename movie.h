#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

using namespace std; 

//inherits from parent product
class Movie : public Product{
  public:
  Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const::string rating); 
  std::set<std::string> keywords() const; 
  string displayString() const; 
  void dump(std::ostream& os) const; 

//genre and rating are protected classes 
  protected:
  string genre_; 
  string rating_; 
  std::set<std::string> keywords_; 
  std::string display; 

}; 
#endif