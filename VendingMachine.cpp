#include "VendingMachine.h"
#include <string>

using namespace std;

VendingMachine::VendingMachine(string machineName)
    {
        m_machineName = machineName;
    }

void VendingMachine::stockItem(Item item)
    {
        m_items[item.getName()] = item;
    }

bool VendingMachine::selectItem(string name)
    {
        auto item = m_items.find(name);
        if (item == m_items.end())
            {
                return false;
            }

        if (item->second.getQuantity() <= 0)
            {
                return false;
            }

        item->second.decreaseQuantity();
        return true;
}

string VendingMachine::getName()
    {
        return m_machineName;
    }

void VendingMachine::getItem(string name, float cost)
    {
        auto item = m_items.find(name);
        if (item == m_items.end())
            {
                return;
            }

        cout << "Item " << item->second.getName() << " with cost " << item->second.getCost() << " is selected." <<endl;
}

void VendingMachine::showItems()
    {
        cout << "List of items in vending machine " << m_machineName << ":" << endl;

        for (auto &item : m_items)
            {
                cout << item.second.getName() << " with cost " << item.second.getCost() << " and quantity " << item.second.getQuantity() << endl;
            }
}
