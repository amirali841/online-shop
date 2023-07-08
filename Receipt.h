#ifndef RECEIPT_H_INCLUDED
#define RECEIPT_H_INCLUDED
#include <iostream>
#include "Date.h"
#include "Product.h"
#include <map>
#include <vector>
using namespace std;
class Receipt
{
public:
    Receipt(Date &d) { date = d; }
    double get_total_price();
    void static_use();
private:
    friend class Customer;
    friend class Store;
    vector<Product> pro_quantity;
    Date date;
    map<int,int> product_quantity;
};

#endif // RECEIPT_H_INCLUDED
