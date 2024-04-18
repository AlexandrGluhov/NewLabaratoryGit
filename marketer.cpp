#include "marketer.h"
#include <iostream>

string Marketer::get_product()
{
    return product;
}

void Marketer::read_from_console()
{
    Employee::read_from_console();
    cout << "Введите продукт к которому прикреплен работник: ";
    cin >> product;
}

std::ostream& operator<<(std::ostream& os, Marketer mar)
{
    Employee emp = static_cast<Employee> (mar);
    return os << emp << ' ' << mar.get_product();
}

std::istream& operator>>(std::istream& in, Marketer & mar)
{
    Employee *cast_employee = static_cast<Employee *> (&mar);
    in >> *cast_employee ;
    in >> mar.product;
    return in;
}

std::ofstream& operator<<(std::ofstream& ofs, Marketer mar)
{
    Employee emp = static_cast<Employee> (mar);
    ofs << emp << ' ' << mar.get_product();
    return ofs;
}

std::ifstream& operator>>(std::ifstream& in, Marketer &mar)
{
    Employee *cast_employee = static_cast<Employee *> (&mar);
    in >> *cast_employee >> mar.product;
    return in;
}