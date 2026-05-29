#ifndef CART_H
#define CART_H

#include <iostream>
#include <vector>
#include <string>
#include "MenuItem.h"
#include "Restaurants.h"

class Cart{
private:
    Restaurant* restaurant;
    vector<MenuItem> items;
public:
    void addToCart(MenuItem item){
        if(!restaurant){
            cerr << "Cart: Set a restaurant before adding items." << endl;
        }
        items.push_back(item);
    }

    double totalCost() const{
        double totalCost = 0;
        for(const auto item : items){
            totalCost += item.getPrice();
        }
        return totalCost;
    }

    bool isEmpty(){
        return (!restaurant || items.empty());
    }

    void clear(){
        items.clear();
        restaurant = nullptr;
    }

    void setRestaurant(Restaurant* r){
        restaurant = r;
    }

    const vector<MenuItem> getItems() const{
        return items;
    }

};

#endif // !CART_H
