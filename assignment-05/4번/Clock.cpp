#include "Clock.h"
// 멤버를 초기화한 뒤 입력된 초를 시·분·초로 변환한다.
Clock::Clock() : second(0), minute(0), hour(0) {
    int sec = 0;
    if (std::cin >> sec) setTime(sec);
}
void Clock::setTime(int se) {
    // 음수도 하루 범위로 정규화한다.
    se = ((se % 86400) + 86400) % 86400;
    setHour(se); setMinute(se); setSecond(se);
}
void Clock::setHour(int h) { hour = h / 3600; }
void Clock::setMinute(int m) { minute = (m % 3600) / 60; }
void Clock::setSecond(int s) { second = s % 60; }
void Clock::increaseHour() { hour = (hour + 1) % 24; }
void Clock::increaseMinute() {
    ++minute;
    if (minute == 60) { minute = 0; increaseHour(); }
}
void Clock::increaseSecond() {
    ++second;
    if (second == 60) { second = 0; increaseMinute(); }
}
void Clock::Cout() { std::cout << hour << " : " << minute << " : " << second << std::endl; }
Clock::~Clock() { std::cout << hour << " : " << minute << " : " << second << std::endl; }
