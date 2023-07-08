#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(int z , string s1 , float f1 , string s2 , Date d1)
{
    this->id = z;
    this->name = s1;
    this->price = f1;
    this->brand = s2;
    this->expire_date = d1;
}



ostream &operator<<(ostream &output , Product &pro)
{
    cout << "Product's ID: " << pro.id << endl;
    cout << "Product's Name: " << pro.name << endl;
    cout << "Product's Price: " << pro.price << endl;
    cout << "Product's Brand: " << pro.brand << endl;
    cout << "Product's Expire Date: " << pro.expire_date << endl;

}

int Product::operator==(Product &p)
{
    if((id == p.id) && (brand == p.brand) && (expire_date == p.expire_date) && (name == p.name) && (price == p.price))
        return 1;
    return 0;
}
