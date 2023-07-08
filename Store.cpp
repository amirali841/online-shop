#include "Store.h"
#include <vector>
#include <iostream>
#include <map>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <iomanip>
using namespace std;

Store::Store(Date &d)
{
    date = d;
    read_data();
}

void Store::add_sth_to_stock(int pro_id , int quantity)
{
    for(auto it = list_of_products.begin() ; it != list_of_products.end() ; it++)
        if(it->id == pro_id)
            {stock.change_count_by(pro_id , quantity);  return;}
    cout << "This Product_ID Does not Exist In The List of products." << endl;
    return;
}

void Store::add_sth_to_customer_cart(int cust_id , int pro_id , int quantity)
{
    for(auto itt = list_of_products.begin() ; itt != list_of_products.end() ; itt++)
    {
        if(itt->id == pro_id)
            for(auto it = list_of_customers.begin() ; it != list_of_customers.end() ; it++)
                if(it->id == cust_id)
                {
                    if(quantity > stock.get_count(pro_id))
                        {cout << "there is not enough amount of this product" << endl; return;}
                    if(quantity <= stock.get_count(pro_id))
                        {it->cust_cart.add(pro_id,quantity); return;}
                }
    }
    cout << "Customer_ID or Product_ID Does not Exist In The List of customers." << endl;
    return;
}

void Store::check_out(int z)
{
    map<int,int>::iterator itr;
    for(auto it = list_of_customers.begin() ; it != list_of_customers.end() ; it++)
        if(z == it->id)
        {
            if(!it->cust_cart.list_cart.empty())
            {
                it->convert_cart_to_receipt();
                auto itt = (it->history_of_receipts.end() - 1);
                for(itr = itt->product_quantity.begin() ; itr != itt->product_quantity.end() ; itr++)
                    stock.change_count_by(itr->first , -(itr->second));
                return;
            }
            cout << "This Customer Is Not In The Store!." << endl;
            return;
        }
    cout << "This Customer_ID Does not Exist In The List of customers." << endl;
    return;

}

void Store::add_customer()
{
    cout << "Getting Customer's Information........" << endl;
    int id;
    cout << "Enter Customer's ID: ";
    cin >> id;
    string name;
    cout << "Enter Customer's Name: ";
    getline(cin , name);
    while(name.length() == 0)
        getline(cin , name);
    string phone_number;
    cout << "Enter Customer's Phone Number: ";
    getline(cin , phone_number);
    while(phone_number.length() == 0)
        getline(cin , phone_number);
    string address;
    cout << "Enter Customer's Address: ";
    getline(cin , address);
    while(address.length() == 0)
        getline(cin , address);
    double balance;
    cout << "Enter Customer's Balance: ";
    cin >> balance;
    for(auto it = list_of_customers.begin() ; it != list_of_customers.end() ; it++)
        if(id == it->id)
        {
            cout << "This Customer Is Already In The List!." << endl;
            return;
        }
    Customer cust1(id , name , phone_number , address , balance);

    list_of_customers.push_back(cust1);
}

void Store::add_product()
{
    cout << "Getting Product's Information........" << endl;
    int id;
    cout << "Enter Product's ID: ";
    cin >> id;
    string name;
    cout << "Enter Product's Name: ";
    getline(cin , name);
    while(name.length() == 0)
        getline(cin , name);
    float price;
    cout << "Enter Product's Price: ";
    cin >> price;
    string brand;
    cout << "Enter Product's Brand: ";
    getline(cin , brand);
    while(brand.length() == 0)
        getline(cin , brand);
    int y , m , d;
    cout << "Enter Product's Expire_Date's year: ";
    cin >> y;
    cout << "Enter Product's Expire_Date's month: ";
    cin >> m;
    cout << "Enter Product's Expire_Date's day: ";
    cin >> d;
    int number_in_stock;
    cout << "enter the amount in stock: ";
    cin >> number_in_stock;
    Date d1(y,m,d);
    Product Pro1(id , name , price , brand , d1);
    for(auto it = list_of_products.begin() ; it != list_of_products.end() ; it++)
        {
            if (Pro1 == (*it))
            {
                cout << "This product already exists on the list!" << endl;
                stock.change_count_by(id , 1);
                cout << "number of this product has been increased by one." << endl;
                return;
            }
            else
            {
                if(it->id == Pro1.id)
                {
                    cout << "This product already exists on the list!" << endl;
                    cout << "you can't add a product with an ID that already exists on the list!" << endl;
                    return;
                }
            }
        }
    list_of_products.push_back(Pro1);
    stock.pro_stock.insert(pair<int,int>(id , number_in_stock));
}

void Store::view_products()
{
    int i = 1;
    for(auto it = list_of_products.begin(); it != list_of_products.end() ; it++ , i++)
        cout << "#" << i << " Product:" << endl << *it << endl;
}

void Store::save_to_file()
{
    ofstream fout;
    fout.open("Store.txt");
    for(auto it = list_of_products.begin() ; it != list_of_products.end() ; it++)
    {
        fout << "PRODUCT: " << endl;
        fout << "- ID: " << it->id << endl;
        fout << "- Name: " << it->name << endl;
        fout << "- Price: " << it->price << endl;
        fout << "- Brand: " << it->brand << endl;
        fout << "- Expire date: " << setfill('0') << setw(4) << it->expire_date.year << "/" << setfill('0') << setw(2) << it->expire_date.month << "/" << setfill('0') << setw(2) << it->expire_date.day << endl;
        fout << "- In stock: " << stock.get_count(it->id) << endl;
    }
    for(auto it = list_of_customers.begin() ; it != list_of_customers.end() ; it++)
    {
        fout << "CUSTOMER: " << endl;
        fout << "- ID: " << it->id << endl;
        fout << "- Name: " << it->name << endl;
        fout << "- Phone number: " << it->phone_number << endl;
        fout << "- Address: " << it->address << endl;
        fout << "- Balance: " << it->balance << endl;
        map<int,int>::iterator itr;

        fout << "Customer's Receipt History: " << endl;
        for(auto ittt = it->history_of_receipts.begin() ; ittt != it->history_of_receipts.end() ; ittt++)
        {
            fout << "RECEIPT: " << endl;
            fout << "Date: " << setfill('0') << setw(4) << ittt->date.year << "/" << setfill('0') << setw(2) << ittt->date.month << "/" << setfill('0') << setw(2) << ittt->date.day << endl;
            for(itr = ittt->product_quantity.begin() ; itr != ittt->product_quantity.end() ; itr++)
                fout << itr->second << " product(s) with ID: " << itr->first << " added to the Receipt" << endl;
        }
        fout << "CART: " << endl;
        for(itr = it->cust_cart.list_cart.begin() ; itr != it->cust_cart.list_cart.end() ; itr++)
            fout << "Customer added " << itr->second << " Product(s) with ID: " << itr->first << " to their Cart" << endl;
    }
    fout << "STOCK: " << endl;
    map<int,int>::iterator ss;
    for(ss = stock.pro_stock.begin() ; ss != stock.pro_stock.end() ; ss++)
        fout << "Number of Product(s) with ID: " << ss->first << " is " << ss->second << endl;
    fout.close();
}

void Store::sales_report(Date &d1 , Date &d2)
{
    Date tempd = d1;
    double x = 0;
    double ans = 0;
    int i = 0;
    map<int,double> s;
    while(tempd != (d2 + 1))
    {
        cout << tempd << ":";
        for(auto it1 = list_of_customers.begin() ; it1 != list_of_customers.end() ; it1++)
            for(auto it2 = it1->history_of_receipts.begin() ; it2 != it1->history_of_receipts.end() ; it2++)
                if(it2->date == tempd)
                    x += it2->get_total_price();
        s[i] = x;
        x /= 100;
        while(x >= 1)
        {
            cout << "++ ";
            x--;
        }
        cout << endl;
        tempd++;
        i++;
    }
    for(int m = 0 ; m < i+ 1 ; m++)
        if(s[m] == find_max(s , i+1))
            cout << "maximum sale was on the Day: " << d1 + m << endl;
    for(int m = 0 ; m < i+ 1 ; m++)
        ans += s[m];
        cout << "total sales amount is equal to: " << ans << endl;

}

double Store::find_max(map<int,double> s , int n)
{
    if(n == 1)
        return s[0];
    return max(s[n-1] ,find_max(s , n-1));
}

void Store::read_data()
{
    ifstream fin;
    fin.open("Store.txt");
    int m;
    number_of_lines = 0;
    string tmp;
    while(fin)
    {
        getline(fin, tmp);
        str[number_of_lines] = tmp;
        number_of_lines++;
    }
    str.erase(number_of_lines);
    number_of_lines--;

    //------------------------------------------------------

    for(int i = 0 ; str[i] == "PRODUCT: " ; i += 7)
    {
        int n = stoi(str[i+1].substr(6 , 1000));
        string s1 = str[i+2].substr(8 , 1000);
        float f = std::stof(str[i+3].substr(9,1000));
        string s2 = str[i+4].substr(9 , 1000);
        int year = stoi(str[i+5].substr(15 , 4));
        int month = stoi(str[i+5].substr(20 , 2));
        int day = stoi(str[i+5].substr(23 , 2));
        int number_in_stock = stoi(str[i+6].substr(12 , 1000));
        Date d(year,month,day);
        Product pr(n , s1 , f , s2 , d);
        list_of_products.push_back(pr);
        stock.pro_stock.insert(pair<int,int>(n,number_in_stock));
        m = i;
    }
    m += 7;
    int zzz;
    int xxx;
    int yyy = m;
    for(int i = m ; str[i] == "CUSTOMER: " ; i += (xxx + 8))
    {
        xxx = 0;
        int n = stoi(str[i+1].substr(6 , 1000));
        string s1 = str[i+2].substr(8 , 1000);
        string s2 = str[i+3].substr(16 , 1000);
        string s3 = str[i+4].substr(11 , 1000);
        double d = stod(str[i+5].substr(11 , 1000));
        Customer cus(n , s1 , s2 , s3 , d);
        for(int z = i + 7 ; str[z] == "RECEIPT: " ; z += zzz)
        {
            zzz = 2;
            Receipt re(date);
            re.date.year = stoi(str[z+1].substr(6 , 4));
            re.date.month = stoi(str[z+1].substr(11 , 2));
            re.date.day = stoi(str[z+1].substr(14 , 2));
            for(int f = z + 2 ; (str[f] != "RECEIPT: ") && (str[f] != "CART: ") ; f++)
            {
                re.product_quantity.insert(pair<int,int>(return_int(str[f] , (countDigit(return_int(str[f] , 0)) + 21)) , return_int(str[f] , 0)));
                zzz++;
            }
            xxx += zzz;
            cus.history_of_receipts.push_back(re);
        }
        if(str[xxx+i+7] == "CART: ")
            for(int k = xxx + i + 7 + 1 ; (str[k] != "CUSTOMER: ") && (str[k] != "STOCK: "); k++)
            {
                cus.cust_cart.add(return_int(str[k] , countDigit(return_int(str[k] , 15)) + 36) , return_int(str[k] , 15));
                xxx++;
            }
        list_of_customers.push_back(cus);
        yyy += (xxx + 8);
    }
    for(int i = yyy + 1 ; i < number_of_lines ; i++)
        stock.pro_stock[return_int(str[i] , 30)] = return_int(str[i] , countDigit(return_int(str[i] , 30)) + 30 + 4);
}

int Store::return_int(string s , int z)
{
    string tmp;
    int ans;
    for(int i = z ; (s[i] >= '0' && s[i] <= '9') ; i++)
        tmp += s[i];
    ans = stoi(tmp);
    return ans;
}

int Store::countDigit(int n)
{
   if(n == 0)
     return 1;
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

void Store::print_cart_of_a_customer(int customer_id)
{
    for(auto it = list_of_customers.begin() ; it != list_of_customers.end() ; it++)
        if(customer_id == it->id)
            {it->cust_cart.print(); return;}
    cout << "This ID Does not Exist In The List of customers." << endl;
    return;
}

void Store::remove_sth_from_customer_cart(int customer_id , int pro_id)
{
    for(auto it = list_of_customers.begin() ; it != list_of_customers.end() ; it++)
        if(customer_id == it->id)
            {it->cust_cart.remove_item(pro_id); return;}
    cout << "This Customer_ID Does not Exist In The List of customers." << endl;
    return;
}

void Store::reset_cart_of_customer(int customer_id)
{
    for(auto it = list_of_customers.begin() ; it != list_of_customers.end() ; it++)
        if(it->id == customer_id)
            {it->cust_cart.reset(); return;}

    cout << "This Customer_ID Does not Exist In The List of customers." << endl;
    return;
}

double Store::get_total_price_of_customer_cart(int customer_id)
{
    for(auto it = list_of_customers.begin() ; it != list_of_customers.end() ; it++)
        if(it->id == customer_id)
            return (it->cust_cart.get_total_price());
    cout << "This Customer_ID Does not Exist In The List of customers." << endl;
    return -1;
}

int Store::get_count_of_sth_in_stock(int product_id)
{
    for(auto itt = list_of_products.begin() ; itt != list_of_products.end() ; itt++)
        if(itt->id == product_id)
            return stock.get_count(product_id);
    cout << "This Product_ID Does not Exist In The List of products." << endl;
    return -1;
}

double Store::use_get_total_purchase_amount(int customer_id)
{
    for(auto it = list_of_customers.begin() ; it != list_of_customers.end() ; it++)
        if(it->id == customer_id)
            return it->get_total_purchace_amount();
    cout << "This Customer_ID Does not Exist In The List of customers." << endl;
    return -1;
}

void Store::use_convert_cart_to_receipt(int customer_id)
{
    for(auto it = list_of_customers.begin() ; it != list_of_customers.end() ; it++)
        if(it->id == customer_id)
        {
            it->convert_cart_to_receipt();
            return;
        }
    cout << "This Customer_ID Does not Exist In The List of customers." << endl;
    return;
}


void Store::show_data()
{
    for(int m = 0 ; m  < number_of_lines ; m++)
        cout << str[m] << endl;
}
