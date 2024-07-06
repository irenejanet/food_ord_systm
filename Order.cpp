#include "Order.h"
#include <iostream>

// method to add  an item to the order
void Order::addItem(const Item& item) {
    items.push_back(item);
}


void Order::removeItem(int index) {
    if (index >= 0 && index < items.size()) {
        items.erase(items.begin() + index);
    }
}


void Order::printOrder() const {
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << (i + 1) << ". " << items[i].getName() << " - $" << items[i].getPrice();
        if (items[i].isVegetarian()) {
            std::cout << " (Veg)";
        }
        std::cout << std::endl;
    }
}

double Order::getTotalPrice() const {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.getPrice();
    }
    return total;
}

bool Order::isEmpty() const {
    return items.empty();
}

int Order::getOrderSize() const {
    return items.size();
}
