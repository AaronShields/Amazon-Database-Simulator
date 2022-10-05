#include <sstream>
#include <iomanip>
#include "book.h"
#include "product.h"
#include "util.h"

using namespace std; 


Book::Book(const std::string category, const std::string name, double price, int qty, const string author, const string ISBN):

Product(category, name, price, qty)

{
  author_name = author; 
  ISBN_num = ISBN; 

  set<string>::iterator it; 
  
    set<string>author_words = parseStringToWords(author_name); 
      for(it = author_words.begin(); it!= author_words.end(); it++){
        string temp = *it; 
        string lowercase_temp = convToLower(temp); 
        keywords_.insert(lowercase_temp); 
      }
  
  keywords_.insert(ISBN_num); 

  set<string>receive_name = parseStringToWords(name); 
  for(it = receive_name.begin(); it!=receive_name.end(); ++it){
    string temp = *it; 
    string lowercase_temp = convToLower(temp); 
    keywords_.insert(lowercase_temp); 
  } 

}

//implimenting keywords() #3
set<string>Book::keywords() const
{
  return keywords_; 
}
//implementation of displayString() #3
string Book::displayString() const
{
  std::stringstream display; 
  display << name_ << endl; 
  display << "Author:" << author_name << " " << "ISBN: "<< ISBN_num << endl; 
  display << price_ << " " << qty_ << " left" << endl; 
  string display_string = display.str(); 
  return display_string; 
}

void Book::dump(std::ostream& os) const
{
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << ISBN_num << "\n" << author_name << endl; 
}