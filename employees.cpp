#include "employees.h"
#include "marketer.h"
#include <iostream>

using namespace std;

void Employees::read_from_file()
{
    string filename;
    cout << "Введите имя файла, с которого хотите считать данные: ";
    cin >> filename;
    ifstream file;
    file.open(filename);
    if (file.is_open())
    {
        int previous = employees.size();
        int size;
        file >> size;
        size += previous;
        employees.resize(size);
        for (int i = previous, j = 1; i < size; i++, j++)
        {
            string type;
            file >> type;
            if (type == "mar")
            {
                Marketer *mar = new Marketer;
                file >> *mar;
                employees[i] = mar;
            }
            else if (type == "dev")
            {
                Developer *dev = new Developer;
                file >> *dev;
                employees[i] = dev;
            }

            if (!((*employees[i]).get_bdate().is_valid()))
            {
                cout << "Значения даты работника " << j << " введены некорректно! Месяц: " << (*employees[i]).get_bdate().get_month() << ", День: " << (*employees[i]).get_bdate().get_day() << "\n";
                size--;
                employees.resize(size);
                i--;
            }
        }
        file.close();
        cout << "Чтение файла прошло успешно" << endl;
    }
    else
    {
        cout << "Во время чтения файла произошла ошибка, возможно имя файла введено неверно" << endl;
    }
}

void Employees::push_in_file()
{
    string filename;
    cout << "Введите имя файла в который хотите записать данные: ";
    cin >> filename;
    ofstream file;
    file.open(filename);
    if (file.is_open())
    {
        file << employees.size() << endl;
        for (int i = 0; i < employees.size(); i++)
        {
            if (employees[i]->get_division() == "Разработка")
            {
                file << "dev " << *(static_cast<Developer *>(employees[i])) << endl;
            }
            else
            {
                file << "mar " << *(static_cast<Marketer *>(employees[i])) << endl;
            }
        }
        file.close();
        cout << "Запись в файл прошла успешно" << endl;
    }
    else
    {
        cout << "Во время записи в файл произошла ошибка" << endl;
    }
}

void Employees::read_from_console()
{
    employees.resize(employees.size() + 1);
    cout << "Работника какого отдела вы хотите вписать? ";
    string division;
    cin >> division;
    if (division == "Разработка")
    {
        Developer *emp = new Developer;
        employees[employees.size() - 1] = emp;
        emp->read_from_console();
    }
    else if (division == "Маркетинг")
    {
        Marketer *emp = new Marketer;
        employees[employees.size() - 1] = emp;
        emp->read_from_console();
    }
    else
    {
        cout << "Такого отдела не существует!" << endl;
        return;
    }
}

void Employees::print_everything()
{
    for (int i = 0; i < employees.size(); i++)
    {
        cout << i << ") ";
        if (employees[i]->get_division() == "Разработка")
        {
            cout << *(static_cast<Developer *>(employees[i])) << endl;
        }
        else
        {
            cout << *(static_cast<Marketer *>(employees[i])) << endl;
        }
    }
}

void Employees::remove_employee()
{
    cout << "Какого работника вы хотите удалить?" << endl;
    print_everything();
    int n;
    cin >> n;
    employees.erase(employees.begin() + n);
}

void Employees::print_everyone_in()
{
    string choice;
    cout << "Введите название отдела: ";
    cin >> choice;
    for (int i = 0; i < employees.size(); i++)
    {
        if ((*employees[i]).get_division() == choice)
        {
            cout << *employees[i] << endl;
        }
    }
}

void Employees::print_everyone_older()
{
    for (int i = 0; i < employees.size(); i++)
    {
        int age = (*employees[i]).get_age();
        if (age > 50)
        {
            if (employees[i]->get_division() == "Разработка")
            {
                cout << *(static_cast<Developer *>(employees[i])) << endl;
            }
            else
            {
                cout << *(static_cast<Marketer *>(employees[i])) << endl;
            }
        }
    }
}

void Employees::employees_compare()
{
    cout << "Какие записи вы хотите сравнить?" << endl;
    print_everything();
    cout << "Введите номер первой записи: ";
    int i1;
    cin >> i1;
    cout << "Введите номер второй записи: ";
    int i2;
    cin >> i2;
    if (employees[i1] == employees[i2])
    {
        cout << "Записи под номерами " << i1 << " и " << i2 << " равны!" << endl;
    }
    else
    {
        cout << "Записи под номерами " << i1 << " и " << i2 << " НЕ равны!" << endl;
    }
}

Employees::Employees()
{
    read_from_file();
}

Employees::~Employees()
{
    employees.clear();
}

Employees Employees::operator+=(Employees emp)
{
    employees.insert(employees.end(), emp.employees.begin(), emp.employees.end());
    return *this;
}

Employees Employees::operator+=(Employee *emp)
{
    employees.push_back(emp);
    return *this;
}

Employees Employees::operator-=(Employee *emp)
{
    for (int i = 0; i < employees.size(); i++)
    {
        if (*employees[i] == *emp)
        {
            employees.erase(employees.begin() + i);
        }
    }
    return *this;
}

void Employees::push_menu()
{
    int choice;
    while (choice != 8)
    {
        cout << "Выберите действие:" << endl;
        cout << "0) Считать значения с файла" << endl;
        cout << "1) Считать значения с консоли" << endl;
        cout << "2) Вывести данные обо всех сотрудниках" << endl;
        cout << "3) Вывести данные обо всех сотрудниках в конкретном отделе" << endl;
        cout << "4) Вывести данные обо всех сотрудниках старше 50 лет" << endl;
        cout << "5) Удалить сотрудника" << endl;
        cout << "6) Проверить записи на схожесть" << endl;
        cout << "7) Записать данные в файл" << endl;
        cout << "8) Выход" << endl;
        cin >> choice;
        switch (choice)
        {
        case (0):
            read_from_file();
            break;
        case (1):
            read_from_console();
            break;
        case (2):
            print_everything();
            break;
        case (3):
            print_everyone_in();
            break;
        case (4):
            print_everyone_older();
            break;
        case (5):
            remove_employee();
            break;
        case (6):
            employees_compare();
            break;
        case (7):
            push_in_file();
            break;
        case (8):
            cout << "Завершение работы программы" << endl;
            break;
        default:
            cout << "Такой фукнции нет, повторите попытку" << endl;
            break;
        }
    }
}