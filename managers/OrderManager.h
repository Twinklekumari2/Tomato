#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <iostream>
#include <vector>
#include "../models/Order.h"
using namespace std;

class OrderManager{
private:
    vector<Order*> orders;
    static OrderManager* instance;

    OrderManager(){

    }
public:
    static OrderManager* getInstance(){
        if(!instance){
            instance = new OrderManager();
        }
        return instance;
    }

    void addOrders(Order* order){
        orders.push_back(order);
    }

    void listOrder(){
        cout << "\n---- All Orders ----\n";
        for(auto order : orders){
            cout << order->getType() << " order for " << order->getUser()->getName() << " | Totak: " << order->getTotal() << " | At: " << order->getScheduled() << endl; 
        }
    }
};

OrderManager* OrderManager::instance = nullptr;

#endif // !ORDER_MANAGER_H