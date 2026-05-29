#ifndef PAYMENT_STRATEGY_H
#define PAYMENT_STRATEGY_H

#include <iostream>
using namespace std;

class PaymentStrategy{
public:
    virtual void pay(double amount) {};
    virtual ~PaymentStrategy(){}
};

#endif // !PAYMENT_STRATEGY_H