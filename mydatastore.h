#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include "product.h"
#include "user.h"
#include "movie.h"
#include "clothing.h"
#include "book.h"
#include "datastore.h"
#include "util.h"

class MyDataStore: public DataStore{
  public:
    ~MyDataStore(); 

  /**
     * Adds a product to the data store
     */
    virtual void addProduct(Product* p) = 0;

    /**
     * Adds a user to the data store
     */
    virtual void addUser(User* u) = 0;

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    virtual std::vector<Product*> search(std::vector<std::string>& terms, int type) = 0;

    /**
     * Reproduce the database file from the current Products and User values
     */
    virtual void dump(std::ostream& ofile) = 0;

protected:
std::vector<Product*> items; 
std::set<User*> users;
std::map<string, vector<Product*>> carts; 
std::map<string, set<Product*>> keywordmap; 

}; 
#endif

  