#include "employee.h"

class Developer : public Employee
{
private:
    string direction;
    string language;

public:
    Developer();
    string get_direction();
    string get_language();
    virtual void read_from_console();
    friend std::ostream &operator<<(std::ostream &, Developer);
    friend std::istream &operator>>(std::istream &, Developer &);
    friend std::ofstream &operator<<(std::ofstream &, Developer);
    friend std::ifstream &operator>>(std::ifstream &, Developer &);
};