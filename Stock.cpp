#include "Stock.h"
#include <iostream>
using namespace std;


void Stock::change_count_by(int id , int count)
{
    if((pro_stock[id] + count) < 0 )
        cout << "Error In Changing Stock." << endl;
    else
        pro_stock[id] += count;

}

int Stock::get_count(int id)
{
    return pro_stock[id];
}
