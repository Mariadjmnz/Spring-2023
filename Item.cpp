#include "Item.h"
#include <string>

using namespace std;


Item::Item() {}

Item::Item(string name, int quality, float cost)
    {
        m_name = name;
        m_quality = quality;
        m_cost = cost;
    }

string Item::getName()
    {
        return m_name;
    }

int Item::getQuantity()
    {
        return m_quality;
    }

void Item::decreaseQuantity()
    {
        m_quality--;
    }

float Item::getCost()
    {
        return m_cost;
    }
