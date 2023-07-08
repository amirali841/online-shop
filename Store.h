#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED
#include <iostream>
#include "Product.h"
#include "Date.h"
#include "Customer.h"
#include "Stock.h"
#include <vector>
using namespace std;

class Store
{

public:
    Store(Date&);
    void check_out(int);
    void add_customer();
    void add_product();
    void view_products();
    void save_to_file();
    void sales_report(Date& , Date&);
    void read_data();
    int return_int(string , int);
    int countDigit(int);
    void show_data();
    //------------------CART------------------
    void print_cart_of_a_customer(int);
    void add_sth_to_customer_cart(int , int ,int);
    void remove_sth_from_customer_cart(int , int);
    void reset_cart_of_customer(int);
    double get_total_price_of_customer_cart(int);
    //------------------STOCK------------------
    void add_sth_to_stock(int , int);
    int get_count_of_sth_in_stock(int);
    //------------------CUSTOMER------------------
    void use_convert_cart_to_receipt(int);
    double use_get_total_purchase_amount(int);

    static vector<Product> get_VP() { return list_of_products;}
    double find_max(map<int,double> , int);

    ~Store() { save_to_file(); cout << "Closing Program......" << endl; }
private:
    friend class Customer;
    vector<Customer> list_of_customers;
    static vector<Product> list_of_products;
    map<int,string> str;
    Stock stock;
    static Date date;
    int number_of_lines;
};


#endif // STORE_H_INCLUDED
