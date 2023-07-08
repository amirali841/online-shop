#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include "Receipt.h"
#include "Cart.h"
#include <iostream>
#include <vector>
#include <map>
//#include <iterator>
using namespace std;
class Customer
{
public:
    Customer(int = 0, string = " ", string = " ", string= " " , double = 0);
    void convert_cart_to_receipt();
    float get_total_purchace_amount();
    Cart get_cust_cart() { return cust_cart; }
private:
    friend class Store;
    int id;
    string name;
    string phone_number;
    string address;
    double balance;
    Cart cust_cart;
    vector<Receipt> history_of_receipts;
};

#endif // CUSTOMER_H_INCLUDED
