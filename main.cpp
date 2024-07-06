#include "Menu.h"
#include "Order.h"
#include <iostream>
#include <limits>

int getUserChoice(int min, int max) {
    int choice;
    while (true) {
        std::cout << "Enter your choice (" << min << " - " << max << "): ";
        std::cin >> choice;

        if (std::cin.fail() || choice < min || choice > max) {
            std::cin.clear();  // Clear input buffer to restore cin to a usable state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore last input
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
        }
        else {
            break;
        }
    }
    return choice;
}

int main() {
    Menu menu;
    menu.addItem(Item("Burger", 5.99, true));
    menu.addItem(Item("Pizza", 8.99, true));
    menu.addItem(Item("Salad", 4.49, false));
    menu.addItem(Item("Sandwich", 6.99, true));
    menu.addItem(Item("Pasta", 9.99, false));
    menu.addItem(Item("Soda", 1.99, false));
    // Add more items to the menu as needed

    Order customerOrder;

    char option;
    do {
        std::cout << "Select an option:\n";
        std::cout << "1. Display Menu\n";
        std::cout << "2. Add Item to Order\n";
        std::cout << "3. Remove Item from Order\n";
        std::cout << "4. Display Order\n";
        std::cout << "5. Checkout\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;

        switch (option) {
        case '1':
            menu.printMenu();
            break;
        case '2': {
            menu.printMenu();
            int choice = getUserChoice(1, menu.getMenuSize());
            Item selectedItem = menu.getItemByIndex(choice - 1);
            customerOrder.addItem(selectedItem);
            std::cout << "Item added to the order.\n";
            break;
        }
        case '3':
        {
            if (customerOrder.isEmpty()) {
                std::cout << "Cannot remove. Order is empty.\n";
            }
            else {
                customerOrder.printOrder();
                int choice = getUserChoice(1, customerOrder.getOrderSize());  
                customerOrder.removeItem(choice - 1);
                std::cout << "Item removed from the order.\n";
            }
            break;
        }

        case '4':
            customerOrder.printOrder();
            break;
        case '5':
            if (!customerOrder.isEmpty()) {
                std::cout << "Thank you for your order!\n";
                std::cout << "Total Price: $" << customerOrder.getTotalPrice() << "\n";
                return 0;
            }
            else {
                std::cout << "Cannot checkout. Order is empty.\n";
            }
            break;
        case '6':
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid option. Please enter a valid option.\n";
        }
    } while (option != '6');

    return 0;
}

