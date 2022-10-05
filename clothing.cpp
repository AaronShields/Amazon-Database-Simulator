#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "product.h"
#include "util.h"

using namespace std; 

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const string size, const string brand):

Product(category, name, price, qty)

{
  size_ = size; 
  brand_ = brand; 

  set<string>::iterator it; 
  set<string> type_brand = parseStringToWords(brand); 
  for(it = type_brand.begin(); it!= type_brand.end(); ++it)
  {
    string temp = *it; 
    string lowercase_temp = convToLower(temp); 
    keywords_.insert(lowercase_temp); 
  }
  set<string> set_name = parseStringToWords(name); 
  for(it = set_name.begin(); it!= set_name.end(); ++it){
    string temp = *it; 
    string lowercase_temp = convToLower(temp); 
    keywords_.insert(lowercase_temp); 
  }

}

set<string> Clothing::keywords() const
{
  return keywords_; 
}

string Clothing::displayString() const
{
  std::stringstream display; 
  display << name_ << endl;  
  display << "Brand: " << brand_ << " " << "Size: " << size_ << endl; 
  display << price_ << " " << qty_ << "left" << endl; 

  string display_string = display.str(); 
  return display_string; 
}

void Clothing::dump(std:: ostream& os) const
{
  os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl; 
}