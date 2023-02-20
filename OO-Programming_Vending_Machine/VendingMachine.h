#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <iostream>
#include <string>
#include <unordered_map>
#include "Item.h"

using namespace std;

class VendingMachine
    {

        public:
            VendingMachine(string machineName);

            void stockItem(Item item);
            bool selectItem(string name);
            string getName();
            void getItem(string name, float cost);
            void showItems();

        private:
            string m_machineName;
            unordered_map<string, Item> m_items;
    };

#endif
