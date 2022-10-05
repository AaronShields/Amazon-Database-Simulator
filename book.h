#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

using namespace std; 
//book makes reference to parent product
class Book: public Product{
  public:
    Book(const std::string category, const std::string name, double price, int qty, const std::string author, const std::string ISBN); 
    std::set<std::string> keywords() const; 
    std::string displayString() const; 
    void dump(std::ostream& os) const; 
    //public class reflects keywords, display string, and dump 

  protected:
    string author_name;
    string ISBN_num; 
    std::set<std::string> keywords_; 
    std::string display; 
    //author name and isbn num are protected variables as they are unique to book

}; 

#endif
