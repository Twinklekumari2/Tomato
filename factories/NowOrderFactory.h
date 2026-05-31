#ifndef NOW_ORDER_FACTORY_H
#define NOW_ORDER_FACTORY_H

#include <iostream>
#include <string>
#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/TimeUtils.h"
using namespace std;

class NowOrderFactory : public OrderFactory{
public:
    Order* createOrder(User* user, Cart* cart, Restaurant* restaurant, const vector<MenuItem>& menuItems, PaymentStrategy* paymentStrategy, double totalCost, const string& orderType) override{
        Order* order = nullptr;
        if(orderType == "Delivery"){
            auto deliveryOrder = new DeliveryOrder();
            deliveryOrder->setUserAddress(user->getAddress());
            order = deliveryOrder;
        }
        else if(orderType == "Pickup"){
            auto pickupOrder = new PickupOrder();
            pickupOrder->setRestaurantAddress(restaurant->getLocation());
            order = pickupOrder;
        }

        order -> setUser(user);
        order->setItems(menuItems);
        order->setRestaurant(restaurant);
        order->setPaymentStrategy(paymentStrategy);
        order->setScheduled(TimeUtils::getCurrentTime());
        order->setTotal(totalCost);
        return order;
    }
};

#endif // !NOW_ORDER_FACTORY_H