#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H

#include <iostream>
#include <string>
#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/TimeUtils.h"
using namespace std;

class ScheduledOrderFactory : public OrderFactory{
private:
    string scheduledTime;
public:
    ScheduledOrderFactory(string scheduleTime){
        this->scheduledTime = scheduledTime;
    }
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
        order->setScheduled(scheduledTime);
        order->setTotal(totalCost);
        return order;
    }
};

#endif // !SCHEDULED_ORDER_FACTORY_H