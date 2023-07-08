#include "Cart.h"
#include "Store.h"
#include <iostream>
#include <map>
#include <iterator>
using namespace std;


void Cart::print()
{
    static_use();
    map<int,int>::iterator it1;
    for(it1 = list_cart.begin() ; it1 != list_cart.end() ; it1++)
        for(auto it2 = vector_Product.begin() ; it2 != vector_Product.end() ; it2++)
            if(it1->first == it2->id )
            {
                cout << *it2 << endl;
                cout << "quantity of this product is: " << it1->second << endl;
            }
}


void Cart::add(int pro_id , int quantity)
{
    map<int,int>::iterator itr;
    for(itr = list_cart.begin() ; itr != list_cart.end() ; itr++)
        if(itr->first == pro_id)
            itr->second += quantity;
    this->list_cart.insert(pair<int,int>(pro_id,quantity));

}

void Cart::remove_item(int pro_id)
{
    map<int,int>::iterator itr;
    for(itr = list_cart.begin() ; itr != list_cart.end() ; itr++)
        if(itr->first == pro_id)
        {
            list_cart.erase(pro_id);
            return;
        }
    cout << "This Product Does not Exist in cart" << endl;

}

void Cart::reset()
{
    list_cart.clear();
}

double Cart::get_total_price()
{
    double ans = 0;
    static_use();
    map<int,int>::iterator it1;
    for(it1 = list_cart.begin() ; it1 != list_cart.end() ; it1++)
        for(auto it2 = vector_Product.begin() ; it2 != vector_Product.end() ; it2++)
            if(it1->first == it2->id )
                ans += (it2->price * it1->second);
    return ans;
}

void Cart::static_use()
{
    this->vector_Product = Store::get_VP();
}

void Cart::check_out()
{
    reset();
}
