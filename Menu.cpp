#include "Menu.h"
#include <iostream>

void Menu::addItem(const Item& item) {
    items.push_back(item);// adds item to the vector of items
}

void Menu::printMenu() const {
    // menu header
    std::cout << "Menu:\n";
    // loops through the items and prints it
    for (int i = 0; i < items.size(); ++i) {
        std::cout << i + 1 << ". ";
        items[i].print();
    }
}

Item Menu::getItemByIndex(int index) const {
    return items[index]; // returns item at the given index
}

int Menu::getMenuSize() const {
    return items.size(); // reurrns the size of the items vector 
}
