#include "employee.h"

class Marketer : public Employee
{
private:
    string product;

public:
    string get_product();
    virtual void read_from_console();
    friend std::ostream &operator<<(std::ostream &, Marketer);
    friend std::istream &operator>>(std::istream &, Marketer &);
    friend std::ofstream &operator<<(std::ofstream &, Marketer);
    friend std::ifstream &operator>>(std::ifstream &, Marketer &);
};