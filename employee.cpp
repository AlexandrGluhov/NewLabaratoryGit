#include "employee.h"
#include <iostream>

int Employee::get_age()
{
    int age = 2023 - bdate.get_year();
    if (bdate.get_month() > 9 || bdate.get_month() == 9 && bdate.get_day() > 13)
    {
        age--;
    }
    return age;
}

void Employee::read_from_console()
{
    cout << "Введите фамилию работника: ";
    cin >> surname;
    cout << "Введите имя работника: ";
    cin >> name;
    cout << "Введите отчество работника: ";
    cin >> patronymic;
    do
    {
        bdate.init_date_from_console();
    } while (!bdate.is_valid());
    cout << "Введите отдел работника: ";
    cin >> division;
    cout << "Введите должность работника: ";
    cin >> position;
}

bool Employee::operator==(Employee emp)
{
    return surname == emp.surname && name == emp.name && 
    patronymic == emp.patronymic && bdate == emp.bdate &&
    division == emp.division && position == emp.position;
}

string Employee::get_surname()
{
    return surname;
}

string Employee::get_name()
{
    return name;
}

string Employee::get_patronymic()
{
    return patronymic;
}

Date Employee::get_bdate()
{
    return bdate;
}

string Employee::get_division()
{
    return division;
}

string Employee::get_position()
{
    return position;
}

std::ostream& operator<<(std::ostream& os, Employee emp)
{
    return os << emp.get_surname() << ' ' << emp.get_name() << ' ' << emp.get_patronymic() << ' ' << emp.get_bdate() << ' ' << emp.get_division() << ' ' << emp.get_position();
}

std::istream& operator>>(std::istream& in, Employee& emp)
{
    in >> emp.surname >> emp.name >> emp.patronymic >>
    emp.bdate >> emp.division >> emp.position;
    return in;
}

std::ofstream& operator<<(std::ofstream& ofs, Employee emp)
{
    ofs << emp.get_surname() << ' ' << emp.get_name() << ' ' << emp.get_patronymic() << ' ' << emp.get_bdate() << ' ' << emp.get_division() << ' ' << emp.get_position();
    return ofs;
}

std::ifstream& operator>>(std::ifstream& in, Employee& emp)
{
    in >> emp.surname >> emp.name >> emp.patronymic >>
    emp.bdate >> emp.division >> emp.position;
    return in;
}