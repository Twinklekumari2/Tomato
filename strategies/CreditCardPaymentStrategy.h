#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H

#include <iostream>
#include <vector>
#include <string>
#include "PaymentStrategy.h"
using namespace std;

class CredtCardPaymentStratey : PaymentStrategy{
private:
    string cardNumber;
public:
    CredtCardPaymentStratey(const string& card){
        cardNumber = card;
    }
    void pay(double amount) override{
       cout << "Paid  rupee" << amount << " using Credit Card (" << cardNumber << ")" << endl;
    }
};

#endif // !CREDIT_CARD_PAYMENT_STRATEGY_H