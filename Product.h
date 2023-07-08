#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
#include <iostream>
#include "Date.h"
using namespace std;
class Product
{
    friend ostream &operator<<(ostream& , Product&);

public:
    Product(int,string,float,string,Date);
    int get_ID() { return id; }
    int operator==(Product&);
private:
    friend class Cart;
    friend class Receipt;
    friend class Store;
    int id;
    string name;
    double price;
    string brand;
    Date expire_date;
};
#endif // PRODUCT_H_INCLUDED
