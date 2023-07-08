#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>

class Date
{
    friend std::ostream &operator<<(std::ostream&, const Date&);
public:
    explicit Date(unsigned int = 1900, unsigned int = 1, unsigned int = 1);
    Date(const Date&);

    static const std::string monthName[13];
    static const unsigned int daysPerMonth[13];

    void setYear(unsigned int);
    unsigned int getYear() const;
    void setMonth(unsigned int);
    unsigned int getMonth() const;
    void setDay(unsigned int);
    unsigned int getDay() const;
    static bool leap(unsigned int);
    bool endOfMonth(unsigned int);
    void operator=(Date&);
    bool operator==(Date);
    bool operator!=(Date);
    Date operator+(int);
    Date &operator++();
    Date operator++(int);
    Date &operator+=(unsigned int);
    void print() const;

    ~Date();

private:
    friend class Store;
    unsigned int year;
    unsigned int month;
    unsigned int day;

    void increament();

    bool checkDay(unsigned int) const;
};

#endif // DATE_H_INCLUDED
