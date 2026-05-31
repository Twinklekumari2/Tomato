#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include <iostream>
#include <vector>
#include <string>
#include "../models/Order.h"
#include "../models/Cart.h"
#include "../strategies/PaymentStrategy.h"
#include "../models/Restaurants.h"
using namespace std;

class OrderFactory{
public:
    virtual Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>& menuItems, PaymentStrategy* paymentStrategy, double totalCost, const string& orderType) {};

    virtual ~OrderFactory() {}
};
#endif // !ORDER_FACTORY_H