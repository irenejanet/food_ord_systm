#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    // constructor
    Item(const std::string& name, double price, bool isVegetarian);

    // getter methods

    std::string getName() const;

    double getPrice() const;

    bool isVegetarian() const;

    // prints the item details
    void print() const;

private:
    std::string name;// item name
    double price;    // item price
    bool vegetarian;  // bool value to indicate the item is veg
};

#endif

