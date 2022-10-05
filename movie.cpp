#include <sstream>
#include <iomanip>
#include "movie.h"
#include "product.h"
#include "util.h"

using namespace std; 

Movie::Movie(const std::string category, const std::string name, double price, int qty, const string genre, const string rating):

Product(category, name, price, qty)
{
  genre_ = genre; 
  rating_ = rating; 

  set<string>::iterator it; 
  string genre_lowercase = convToLower(genre); 
  keywords_.insert(genre_lowercase);
  set<string> set_name = parseStringToWords(name); 
  for(it = set_name.begin(); it!= set_name.end(); ++it)
  {
    string temp = *it; 
    string lowercase_temp = convToLower(temp); 
    keywords_.insert(lowercase_temp); 
  }

}

set<string> Movie::keywords() const
{
  return keywords_; 
}

string Movie::displayString() const
{
  std::stringstream display; 
  display << name_ << "\n"; 
  display << "Genre:" << genre_ << " " << "Rating:" << rating_ << "\n"; 
  display << price_ << " " << qty_ << " left" << "\n"; 

  string display_string = display.str(); 
  return display_string; 
}

void Movie::dump(std::ostream& os) const
{
  os << category_ << "\n" << name_ << "\n" << qty_ << "\n"<< genre_ << "\n" << rating_ << endl; 
}