#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "review.h"
#include "user.h"
#include "data.h"
#include "util.h"
#include <queue> 
#include <map>
#include <list>
#include <iostream>
using namespace std;

MyDataStore::MyDataStore():
items(), users(),  carts(), keywordmap()
{

}
//Deconstructor
MyDataStore::~MyDataStore(){
for(unsigned int i= 0; i< items.size()); i++){
  delete items[i]; 
}

std::set<User*>::iterator it; 
for(it = users.begin(); it != users.end() ++it){
  delete *it; 
}

void MyDataStore::addProduct(Product* p)
  {
    items.push_back(p);
    set<string> sup_key = p->keywords();
    map<string, set<Product*> >::iterator finder;
    for (set<string>::iterator it=sup_key.begin(); it!=sup_key.end(); ++it)
    {
      finder = keywordmap.find(*it);
      if (finder == keywordmap.end())
      {
        set<Product*> iden_prod;
        iden_prod.insert(p);
        keywordmap.insert(make_pair(*it, iden_prod));
      }
      else
      {
        finder->second.insert(p);
      }

    }

  }
 
void MyDataStore::addUser(User* u)
  {
    vector<Product*> carts;
    users.insert(u);
    carts.insert(make_pair(u->getName(), cart)); 
  }
}

void MyDataStore::dump(std::ostream& ofile)
{
   ofile << "<products>" << "\n";
        for (unsigned int i=0; i< items.size(); i++)
        {

            items[i]->dump(ofile);

        }
        ofile << "</products>" << "\n";
        ofile << "<users" << "\n";


       set<User*>::iterator it;
       for (it = userbase.begin(); it!= users.end(); ++it)
       {

        (*it)->dump(ofile);

       }

       ofile << "</users>" << "\n";
}