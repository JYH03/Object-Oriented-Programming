#pragma once
#include <iostream>
using namespace std;
typedef class Clock
{
public:
    Clock();
    ~Clock();
    void setTime(int se);
    void increaseSecond();
    void increaseMinute();
    void increaseHour();
    void Cout();
private:
    int second;
    int minute;
    int hour;
    void setSecond(int s);
    void setMinute(int m);
    void setHour(int h);
}Clock;
