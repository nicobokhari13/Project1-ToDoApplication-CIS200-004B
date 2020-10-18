#pragma once
#ifndef DATE_H
#define DATE_H
struct Date {
private:
    int month{};
    int day{};
    int year{};
public:
    Date() {};//default constructor
    Date(int m, int d, int y) {
        setMonth(m);
        setDay(d);
        setYear(y);
    }
    int getMonth() { return month; }
    int getDay() { return day; }
    int getYear() { return year; }
    void setMonth(int m) { month = m; }
    void setDay(int d) { day = d; }
    void setYear(int y) { year = y; }
    void copyDate(Date copy) {
        setDay(copy.getDay());
        setMonth(copy.getMonth());
        setYear(copy.getYear());
    }
};
#endif
