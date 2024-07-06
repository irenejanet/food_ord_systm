#ifndef MENU_H
#define MENU_H

#include <vector>
#include "Item.h"

class Menu {
private:
    std::vector<Item> items;// vectors that stores the items in the menu

public:
    // adds an item  to the menu
    void addItem(const Item &item);

    // prints the menu items
    void printMenu() const;

    // gets an item by its index
    Item getItemByIndex(int index) const;

    // gets the no. of items in the menu 
    int getMenuSize() const;
};

#endif // MENU_H

