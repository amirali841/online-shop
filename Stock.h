#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED
#include <iostream>
#include <map>
using namespace std;
class Stock
{
public:
    int get_count(int);
    void change_count_by(int , int);
private:
    friend class Store;
    map<int,int> pro_stock;

};
#endif // STOCK_H_INCLUDED
