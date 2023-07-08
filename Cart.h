#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED
#include "Product.h"
#include <iostream>
#include <map>
#include <vector>
//#include <iterator>
using namespace std;
class Cart
{
public:
    void add(int , int);
    void remove_item(int);
    void reset();
    double   get_total_price();
    void print();
    void check_out();
    void static_use();
private:
    friend class Store;
    friend class Customer;
    vector<Product> vector_Product;
    map<int,int> list_cart;
};

#endif // CART_H_INCLUDED
