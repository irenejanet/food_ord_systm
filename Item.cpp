#include "Item.h"// file header 
#include <iostream>

Item::Item(const std::string& name, double price, bool isVegetarian)
    : name(name), price(price), vegetarian(isVegetarian) {}

std::string Item::getName() const {
    return name; // returns name of the item
}

bool Item::isVegetarian() const {
    return vegetarian; // returns if veg or not
}


double Item::getPrice() const {
    return price;
} // returns the price 

void Item::print() const {
    std::cout << name << " - $" << price;// prints the name & price 
    if (vegetarian) {
        std::cout << " (Veg)";
    }
    std::cout << std::endl;
}