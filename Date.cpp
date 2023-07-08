#include <iostream>
#include "Date.h"
#include <stdexcept>
using namespace std;

const string Date::monthName[13] = {"", "January", "February", "March", "April", "May", "June",
                              "July", "August", "September", "October", "November", "December"};

const unsigned int Date::daysPerMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(unsigned int y, unsigned int m, unsigned int d)
{
    setYear(y);
    setMonth(m);
    setDay(d);
}

Date::Date(const Date &dateToCopy)
{
    setYear(dateToCopy.getYear());
    setMonth(dateToCopy.getMonth());
    setDay(dateToCopy.getDay());
}

void Date::setYear(unsigned int y)
{
    year = y;
}

unsigned int Date::getYear() const
{
    return year;
}

void Date::setMonth(unsigned int m)
{
    if(m >= 1 && m <= 12)
        month = m;
    else
        cout << "invalid month" << endl;
}

unsigned int Date::getMonth() const
{
    return month;
}

void Date::setDay(unsigned int d)
{
    if(checkDay(d))
        day = d;
    else
        throw std::invalid_argument("Invalid day for current month and year!");
}

unsigned int Date::getDay() const
{
    return day;
}

bool Date::leap(unsigned int testYear)
{
    if (testYear % 400 == 0 ||
       (testYear % 4 == 0 && testYear % 100 != 0))
       return true;
    else
        return false;
}

bool Date::endOfMonth(unsigned int testDay)
{
    if(leap(year) && month == 2)
        return testDay == 29;
    else
        return testDay == Date::daysPerMonth[month];
}

void Date::print() const
{
    std::cout << year << "/" << month << "/" << day << std::endl;
}

bool Date::checkDay(unsigned int testDay) const
{

    if(testDay <= daysPerMonth[month])
        return true;
    if((month == 2 && testDay == 29) &&
       (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        return true;
    return false;
}

void Date::increament()
{
    if(!endOfMonth(day))
        ++day;
    else if(month != 12)
    {
        ++month;
        day = 1;
    }
    else
    {
        ++year;
        month = day = 1;
    }
}

Date &Date::operator++()
{
    increament();
    return *this;
}

Date Date::operator++(int)
{
    Date t = *this;
    increament();
    return t;
}

Date &Date::operator+=(unsigned int daysToAdd)
{
    for(unsigned int i = 0; i < daysToAdd; ++i)
        increament();
    return *this;
}

Date::~Date()
{
//    std::cout << "Destructor of date ";
//    print();
}

ostream &operator<<(ostream &output, const Date &date)
{
    output << Date::monthName[date.month] << " " << date.day << ", " << date.year;
    return output;
}

Date Date::operator+(int z)
{
    Date ans = *this;
    for(int i = 1 ; i <= z ; i++)
        ans.increament();
    return ans;

}

bool Date::operator==(Date t)
{
    if((year == t.year) && (month == t.month) && (day == t.day))
        return true;
    return false;
}

bool Date::operator!=(Date t)
{
    if((year != t.year) || (month != t.month) || (day != t.day))
        return true;
    return false;

}

void Date::operator=(Date &d)
{
    year = d.year;
    month = d.month;
    day = d.day;
    return;
}
