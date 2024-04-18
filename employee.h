#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <fstream>
#include "date.h"
using namespace std;

class Employee
{
private:
    string surname;
    string name;
    string patronymic;
    Date bdate;
    string division;
    string position;

public:
    int get_age();
    virtual void read_from_console();

    bool operator==(Employee);
    friend std::ostream& operator<<(std::ostream&, Employee);
    friend std::istream& operator>>(std::istream&, Employee&);
    friend std::ofstream& operator<<(std::ofstream&, Employee);
    friend std::ifstream& operator>>(std::ifstream&, Employee&);

    string get_surname();
    string get_name();
    string get_patronymic();
    Date get_bdate();
    string get_division();
    string get_position();
};

#endif