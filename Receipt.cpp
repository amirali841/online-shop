#include "Receipt.h"
#include "Store.h"
#include <iostream>
#include <map>
#include <iterator>
using namespace std;

double Receipt::get_total_price()
{
    double ans = 0;
    static_use();
    map<int,int>::iterator it1;
    for(it1 = product_quantity.begin() ; it1 != product_quantity.end() ; it1++)
        for(auto it2 = pro_quantity.begin() ; it2 != pro_quantity.end() ; it2++)
            if(it1->first == it2->id )
                ans += (it2->price * it1->second);
    return ans;
}

void Receipt::static_use()
{
    pro_quantity = Store::get_VP();
}
