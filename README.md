# online-shop

Project Documentation

Introduction

This project is a simple implementation of a store management system. It allows you to manage products, customers, and their interactions through a command-line interface. The system provides functionality to add products, add customers, view products, manage customer carts, check out customers, and generate sales reports.


Project Structure

The project consists of several classes:


Store

Product

Customer

Cart

Receipt

Stock

Date

Class Details

Store

The Store class represents the store and manages products, customers, and their interactions. It contains static member variables list_of_products (vector of Product objects) and date (current date of the store).


The class provides several member functions:


add_product(): Adds a new product to the store.

add_customer(): Adds a new customer to the store.

view_products(): Displays all the products in the store.

save_to_file(): Saves the store's data to a file.

print_cart_of_a_customer(int customer_id): Prints the shopping cart of a customer.

remove_sth_from_customer_cart(int customer_id, int product_id): Removes a product from a customer's cart.

add_sth_to_customer_cart(int customer_id, int product_id, int quantity): Adds a product to a customer's cart.

get_total_price_of_customer_cart(int customer_id): Calculates the total price of a customer's cart.

get_count_of_sth_in_stock(int product_id): Retrieves the count of a product in the stock.

use_get_total_purchase_amount(int customer_id): Calculates the total purchase amount of a customer.

reset_cart_of_customer(int customer_id): Resets the shopping cart of a customer.

check_out(int customer_id): Checks out a customer, converts the cart to a receipt, and updates the stock.

sales_report(Date& start_date, Date& end_date): Generates a sales report between two dates.

show_data(): Displays all the data stored in the store.
Product

The Product class represents a product in the store. It has attributes such as ID, name, price, brand, and expiration date. The class provides a constructor to initialize the product with these attributes and overloaded operators for printing the product details.


How to Use

To use the store management system, you need to create an instance of the Store class and call its member functions based on your requirements. The provided code demonstrates the usage of various operations available in the store.


For example, you can add products using the add_product() function, add customers using the add_customer() function, view products using the view_products() function, and manage customer carts using functions like print_cart_of_a_customer(), add_sth_to_customer_cart(), remove_sth_from_customer_cart(), get_total_price_of_customer_cart(), and reset_cart_of_customer().


You can also check out a customer using the check_out() function, which converts the customer's cart to a receipt, updates the stock, and clears the cart. The sales_report() function generates a sales report between two given dates.


To save the store's data to a file, use the save_to_file() function. The data will be saved in the "Store.txt" file.


Cart.h

    Functions:
    
    void print(): Prints the products in the cart and their quantities.
    
    void add(int pro_id, int quantity): Adds a product with a given ID and quantity to the cart.
    
    void remove_item(int pro_id): Removes a product with a given ID from the cart.
    
    void reset(): Clears the cart.
    
    double get_total_price(): Calculates and returns the total price of all products in the cart.
    
    void static_use(): Updates the vector of products in the cart by getting the latest vector from the Store.
    
    void check_out(): Clears the cart.


Date.h

    Constructor:
    
    Date(unsigned int y, unsigned int m, unsigned int d): Initializes a date object with the given year, month, and day.
    
    Date(const Date& dateToCopy): Initializes a date object by copying another date object.


    Getter and Setter Functions:

    void setYear(unsigned int y): Sets the year of the date.
    
    unsigned int getYear() const: Returns the year of the date.
    
    void setMonth(unsigned int m): Sets the month of the date.
    
    unsigned int getMonth() const: Returns the month of the date.
    
    void setDay(unsigned int d): Sets the day of the date.
    
    unsigned int getDay() const: Returns the day of the date.


