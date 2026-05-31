#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include <iostream>
#include <vector>
#include <string>
#include "Order.h"
using namespace std;

class DeliveryOrder : public Order{
public:
    string getType() const override{
        return "Delivery order\n";
    }
};

#endif // !DELIVERY_ORDER_H