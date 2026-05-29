#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "../models/Restaurants.h"

class RestaurantManager{
private:
    static RestaurantManager* instance;
    vector<Restaurant*> restaurant;
    
    RestaurantManager(){
        //pvt ctor
    }
public:
    static RestaurantManager* getInstance(){
        if(!instance){
            instance = new RestaurantManager();
        }
        return instance;
    }
    void addRestaurant(Restaurant* r){
        restaurant.push_back(r);
    }

    vector<Restaurant*> searchByLoc(string loc){
        vector<Restaurant*> result;
        transform(loc.begin(), loc.end(), loc.begin(), ::tolower);
        for(auto r : restaurant){
            string rl = r->getLocation();
            transform(rl.begin(), rl.end(), rl.begin(), ::tolower);
            if(rl == loc){
                result.push_back(r); //if location is found then the details of the restaurants are stored in the result vector and then return to client.
            }
        }
        return result;
    }

};

RestaurantManager* RestaurantManager::instance = nullptr;

#endif // !RESTAURANT_MANAGER_H