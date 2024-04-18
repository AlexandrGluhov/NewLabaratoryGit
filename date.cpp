#include "date.h"
#include <iostream>
#include <fstream>
using namespace std;

bool Date::is_valid()
{
    bool is_valid;
    is_valid = (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day <= 31;
    is_valid |= (month == 4 || month == 6 || month == 9 || month == 11) && day <= 30;
    is_valid |= month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && day <= 29;
    is_valid |= month == 2 && day <= 28;

    return (is_valid);
}

void Date::init_date_from_console()
{
        cout << "Введите дату рождения работника (день) в промежутке от 1 до 31: ";
        cin >> day;
        cout << "Введите месяц рождения работника в промежутке от 1 до 12: ";
        cin >> month;
        cout << "Введите год рождения работника: ";
        cin >> year;
}

unsigned Date::get_day()
{
    return day;
}

unsigned Date::get_month()
{
    return month;
}

unsigned Date::get_year()
{
    return year;
}

bool Date::operator==(Date d)
{
    return year == d.year && month == d.month && day == d.day;
}

std::ostream& operator<<(std::ostream& os, Date d)
{
    os << d.get_day() << ' ' << d.get_month() << ' ' << d.get_year();
    return os;
}

std::istream& operator>>(std::istream& in, Date& d)
{
    in >> d.day >> d.month >> d.year;
    return in;
}

std::ofstream& operator<<(std::ofstream& ofs, Date d)
{
    ofs << d.get_day() << ' ' << d.get_month() << ' ' << d.get_year();
    return ofs;
}

std::ifstream& operator>>(std::ifstream& in, Date& d)
{
    in >> d.day >> d.month >> d.year;
    return in;
}