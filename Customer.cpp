#include "Customer.h"
#include "Store.h"
#include <iostream>
using namespace std;

Customer::Customer(int z , string s1 , string s2 , string s3 , double zz)
{
    id = z;
    name = s1;
    phone_number = s2;
    address = s3;
    balance = zz;
}

void Customer::convert_cart_to_receipt()
{
    Receipt re(Store::date);
    map<int,int>::iterator it;
    for(it = cust_cart.list_cart.begin() ; it != cust_cart.list_cart.end() ; it++)
        re.product_quantity.insert(pair<int,int>(it->first , it->second));
    if(re.get_total_price() > balance)
    {
        cout << "Balance Is not Enough" << endl;
        return;
    }
    balance = balance - re.get_total_price();
    history_of_receipts.push_back(re);
    cust_cart.check_out();
}

float Customer::get_total_purchace_amount()
{
    float ans = 0;
    for(auto it = history_of_receipts.begin() ; it != history_of_receipts.end() ; it++)
        ans += it->get_total_price();
    return ans;
}
