#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include <iostream>
#include <vector>
#include <string>
#include "PaymentStrategy.h"
using namespace std;

class UpiPaymentStratey : PaymentStrategy{
private:
    string mobile;
public:
    UpiPaymentStratey(const string& mob){
        mobile = mob;
    }
    void pay(double amount) override{
       cout << "Paid  rupee" << amount << " using UPI (" << mobile << ")" << endl;
    }
};

#endif // !UPI_PAYMENT_STRATEGY_H