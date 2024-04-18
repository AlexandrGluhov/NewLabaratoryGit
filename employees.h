#ifndef CLASS_EMPLOYEES
#define CLASS_EMPLOYEES
#include <vector>
#include "developer.h"

class Employees
{
private:
    std::vector<Employee *> employees;
    void read_from_file();
    void read_from_console();
    void remove_employee();
    void print_everything();
    void print_everyone_in();
    void print_everyone_older();
    void push_in_file();
    void employees_compare();

public:
    Employees();
    ~Employees();
    void push_menu();
    Employees operator+=(Employees);
    Employees operator+=(Employee *);
    Employees operator-=(Employee *);
};

#endif