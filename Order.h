#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include "Item.h"

class Order {
public:
    // method to add items
    void addItem(const Item& item);

    // method that removes item from the order
    void removeItem(int index);

    // method to print all items
    void printOrder() const;

    // method that gets the total price of order
    double getTotalPrice() const;

    // method that checks if order is empty 
    bool isEmpty() const;

    // method that gets the no. of items in the order
    int getOrderSize() const;

private:
    std::vector<Item> items;
};

#endif

