#include <iostream>
#include "Store.h"
#include "Cart.h"
#include "Date.h"
#include <map>
#include <math.h>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

vector<Product> Store::list_of_products;
Date Store::date;

void Running_Program(Store&);

int main()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    Date date(1900 + ltm->tm_year , 1 + ltm->tm_mon , ltm->tm_mday);
    //----------------------------------------------------------------------------------------------
    Store market(date);
    Running_Program(market);
    return 0;
}


void Running_Program(Store &s)
{
    int x = 0;
    cout << endl << "*************Welcome To The Program*************" << endl;
    cout << "use (show commands) to see all available commands." << endl;
    string input = " ";
    while(input != "exit")
    {
        cout << endl << "Enter a New Command:";
        getline(cin,input);
        while(input.length() == 0)
            getline(cin , input);
        if(input == "show commands")
        {
            cout << "Here's a List of Commands:" << endl;
            cout << "(show data) ----> shows all data" << endl;
            cout << "(show commands) ----> shows all commands" << endl;
            cout << "(save to file) ----> saves data to store.txt" << endl;
            cout << "(add product) ----> adds a new product" << endl;
            cout << "(add customer) ----> adds a new customer" << endl;
            cout << "(view product) ----> shows all products" << endl;
            cout << "(print cart of customer X) ----> prints car of customer with ID: X" << endl;
            cout << "(raise X product Y) ----> increases number of products with ID: Y by X" << endl;
            cout << "(customer X remove product Y) ----> removes a product with ID: Y from customer's cart with ID: X" << endl;
            cout << "(customer X add Y by Z) ----> adds Z product(s) with ID: Y to customer's cart with ID: X" << endl;
            cout << "(get total price of customer cart X) ----> gives total price of customer cart with ID: X" << endl;
            cout << "(get count of product X) ----> shows count of product(s) with ID: X" << endl;
            cout << "(get total purchase amount customer X) ----> gives total purchase amount of customer with ID: X" << endl;
            cout << "(sales report X/X/X to Y/Y/Y) ----> show sales reprot from date X/X/X to Y/Y/Y" << endl;
            cout << "(reset cart of customer X) ----> rests cart of customer with ID: X" << endl;
            cout << "(check out customer X) ----> checks out a customer with ID: X" << endl;
            cout << "(exit) ----> stops the program" << endl;
        }
        if(input == "show data")
            s.show_data();
        if(input.substr(0 , 4) == "save")
            s.save_to_file();
        if(input == "add product")
            s.add_product();
        if(input == "add customer")
            s.add_customer();
        if(input == "view product")
            s.view_products();
        if(input.substr(0 , 22) == "print cart of customer")
            s.print_cart_of_a_customer(s.return_int(input , 23));
        if((input.substr(0 , 8) == "customer") && (input.substr(9 + s.countDigit(s.return_int(input , 9)) + 1 , 6) == "remove"))
            s.remove_sth_from_customer_cart(s.return_int(input , 9) , s.return_int(input , 9 + s.countDigit(s.return_int(input , 9)) + 1 + 6 + 9));
        if(input.substr(0,5) == "raise")
            s.add_sth_to_stock(s.return_int(input , s.countDigit(s.return_int(input , 6)) + 6 + 9) , s.return_int(input , 6));
        if((input.substr(0,8) == "customer") && (input.substr(9 + 1 + s.countDigit(s.return_int(input,9)) , 3) == "add"))
            s.add_sth_to_customer_cart(s.return_int(input,9) , s.return_int(input , 9 + s.countDigit(s.return_int(input,9)) + 5) , s.return_int(input , 9 + 5 + 4 + s.countDigit(s.return_int(input , 9 + s.countDigit(s.return_int(input,9)) + 5)) + s.countDigit(s.return_int(input,9))));
        if(input.substr(0 , 32) == "get total price of customer cart")
            cout << "total price of customer's cart is: " << s.get_total_price_of_customer_cart(s.return_int(input , 33)) << endl;
        if(input.substr(0,5) == "reset")
            s.reset_cart_of_customer(s.return_int(input , 23));
        if(input.substr(0 , 20) == "get count of product")
            cout << "count of this product is: " << s.get_count_of_sth_in_stock(s.return_int(input , 21)) << endl;
        if(input.substr(0 , 34) == "get total purchase amount customer")
            cout << " total purchase amount of this customer is: " << s.use_get_total_purchase_amount(s.return_int(input , 35)) << endl;
        if(input.substr(0,5) == "sales")
        {
            Date d1(s.return_int(input , 13) , s.return_int(input , 13 + s.countDigit(s.return_int(input , 13)) + 1) , s.return_int(input , 13 + 1 + s.countDigit(s.return_int(input , 13)) + s.countDigit(s.return_int(input , 13 + s.countDigit(s.return_int(input , 13)) + 1)) + 1));
            int m = ((13) + (s.countDigit(s.return_int(input , 13)))
                     + (1) + (s.countDigit(s.return_int(input , 13 + s.countDigit(s.return_int(input , 13)) + 1)))
                     + (1) + s.countDigit(s.return_int(input , 13 + 1 + s.countDigit(s.return_int(input , 13)) + s.countDigit(s.return_int(input , 13 + s.countDigit(s.return_int(input , 13)) + 1)) + 1)) + (4));
            Date d2(s.return_int(input , m) , s.return_int(input , m + 1 + s.countDigit(s.return_int(input , m))) , s.return_int(input ,  m + 1 + 1 + s.countDigit(s.return_int(input , m + 1 + s.countDigit(s.return_int(input , m)))) + s.countDigit(s.return_int(input , m))));
            s.sales_report(d1 , d2);
        }
        if(input.substr(0,9) == "check out")
            s.check_out(s.return_int(input , 19));
    }
}
