#ifndef CLASS_DATE
#define CLASS_DATE
#include <fstream>

class Date
{
private:
    unsigned year;
    unsigned month;
    unsigned day;

public:
    bool is_valid();
    void init_date_from_console();
    unsigned get_day();
    unsigned get_month();
    unsigned get_year();

    bool operator==(Date);
    friend std::ostream& operator<<(std::ostream&, Date);
    friend std::istream& operator>>(std::istream&, Date&);
    friend std::ofstream& operator<<(std::ofstream&, Date);
    friend std::ifstream& operator>>(std::ifstream&, Date&);
};

#endif