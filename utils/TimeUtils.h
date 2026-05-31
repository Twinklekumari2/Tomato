#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class TimeUtils{
public:
    static string getCurrentTime(){
        time_t now = time(0); //total second dega, ho 1 jan 1970 se ab tak se seconds ko return karega.
        char* dt = ctime(&now); //ctime -> human readable format mei convert kr dega
        string s(dt); //string mei store ho gya current time but uske last mei \n ye hai toh isko remove krna hai"
        if(!s.empty() && s.back() == '\n') //if strign is not empty then last charcter \n ko remove kr denge
           s.pop_back();
        return s;
    }
};

#endif // !TIME_UTILS_H
