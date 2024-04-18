#include "developer.h"
#include <iostream>

string Developer::get_direction()
{
    return direction;
}

string Developer::get_language() {
    return language;
}

Developer::Developer() {
    direction = "fullstack";
}

void Developer::read_from_console()
{
    Employee::read_from_console();
    cout << "Введите направление разработки: ";
    cin >> direction;
    cout << "Введите язык разработки: ";
    cin >> language;
}

std::ostream& operator<<(std::ostream& os, Developer dev)
{
    Employee emp = static_cast<Employee> (dev);
    return os << emp << ' ' << dev.get_direction() << ' ' << dev.get_language();
}

std::istream& operator>>(std::istream& in, Developer & dev)
{
    Employee *cast_employee = static_cast<Employee *> (&dev);
    in >> *cast_employee ;
    in >> dev.direction >> dev.language;
    return in;
}

std::ofstream& operator<<(std::ofstream& ofs, Developer dev)
{
    Employee emp = static_cast<Employee> (dev);
    ofs << emp << ' ' << dev.get_direction() << ' ' << dev.get_language();
    return ofs;
}

std::ifstream& operator>>(std::ifstream& in, Developer &dev)
{
    Employee *cast_employee = static_cast<Employee *> (&dev);
    in >> *cast_employee >> dev.direction >> dev.language;
    return in;
}