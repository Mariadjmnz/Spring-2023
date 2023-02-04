#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item
    {
        public:
            Item();
            Item(string name, int quality, float cost);

            string getName();
            int getQuantity();
            void decreaseQuantity();
            float getCost();

        protected:

        private:
            string m_name;
            int m_quality;
            float m_cost;
    };

#endif
