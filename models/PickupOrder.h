#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H

#include <iostream>
#include <vector>
#include <string>
#include "Order.h"
using namespace std;

class PickupOrder : public Order{
public:
    string getType() const override{
        return "Pickup order\n";
    }
};

#endif // !PICKUP_ORDER_H