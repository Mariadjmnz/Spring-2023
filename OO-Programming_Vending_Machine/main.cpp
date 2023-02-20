#include <iostream>
#include "VendingMachine.h"
#include <string>

using namespace std;g

int main() {
    string choice;
    float money;

    VendingMachine vm("#01");

    Item coke("Coke", 10, 1.5);
    Item pepsi("Pepsi", 20, 1.75);
    Item water("Water", 15, 1.25);

    vm.stockItem(coke);
    vm.stockItem(pepsi);
    vm.stockItem(water);

    vm.showItems();

    cout << "\n Select item: " << endl;
    cin >> choice;
    cout << "Insert amount: " << endl;
    cin >> money;

    cout << "\n Selecting item " << choice << "..." << endl;
    if (vm.selectItem(choice))
        {
            vm.getItem(choice, money);
            cout << "Transaction was successful." << endl << endl;
        }
    else
        {
            cout << "Item not available." << endl << endl;
        }

    vm.showItems();

    return 0;
}
