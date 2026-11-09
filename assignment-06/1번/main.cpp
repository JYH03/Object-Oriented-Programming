#include "Employee.h"

#include <cerrno>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iostream>

namespace {
constexpr int maxEmployees = 10;

bool isSpace(int ch) {
    return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' || ch == '\f' || ch == '\v';
}

template <std::size_t capacity>
bool readToken(char (&buffer)[capacity]) {
    if (!(std::cin >> std::ws))
        return false;
    std::size_t length = 0;
    bool tooLong = false;
    // 배열이 가득 차도 토큰 끝까지 읽어 다음 명령과 섞이지 않게 한다.
    for (int ch = std::cin.peek(); ch != std::char_traits<char>::eof() && !isSpace(ch);
         ch = std::cin.peek()) {
        std::cin.get();
        if (length + 1 < capacity)
            buffer[length++] = static_cast<char>(ch);
        else
            tooLong = true;
    }
    buffer[length] = '\0';
    return length != 0 && !tooLong;
}

void discardLine() {
    for (char ch; std::cin.get(ch) && ch != '\n';) {}
}

bool readEmployee(char (&name)[100], int& age, char (&country)[100], char (&job)[100]) {
    char ageText[32];
    if (!readToken(name) || !readToken(ageText) || !readToken(country) || !readToken(job))
        return false;
    char* end = nullptr;
    errno = 0;
    const long parsed = std::strtol(ageText, &end, 10);
    if (end == ageText || *end || errno == ERANGE || parsed < INT_MIN || parsed > INT_MAX)
        return false;
    age = static_cast<int>(parsed);
    return true;
}

Employee* findEmployee(Employee* const employees[], int count, const char* name) {
    for (int i = 0; i < count; ++i) {
        if (employees[i]->isNameCorrect(name))
            return employees[i];
    }
    return nullptr;
}

void printEmployee(const Employee& employee) {
    employee.print();
    std::cout << "----------\n";
}
}

int main() {
    Employee* employees[maxEmployees] = {};
    int count = 0;
    char command[10], name[100], country[100], job[100];
    int age = 0;

    while (std::cin) {
        if (!readToken(command)) {
            if (!std::cin || std::cin.eof())
                break;
            std::cout << "Wrong command. Try again.\n";
            discardLine();
            continue;
        }
        if (std::strcmp(command, "insert") == 0) {
            if (count == maxEmployees) {
                std::cout << "already 10 employees exist\n";
                discardLine();
            } else if (readEmployee(name, age, country, job)) {
                employees[count++] = new Employee(name, age, country, job);
            } else {
                std::cout << "Invalid employee information\n";
                discardLine();
            }
        } else if (std::strcmp(command, "find") == 0) {
            if (!readToken(name)) {
                std::cout << "Invalid employee name\n";
                discardLine();
                continue;
            }
            std::cout << "=====find=====\n";
            Employee* employee = findEmployee(employees, count, name);
            if (employee)
                printEmployee(*employee);
            else
                std::cout << "No one has a name like " << name << '\n';
        } else if (std::strcmp(command, "change") == 0) {
            if (!readToken(name)) {
                std::cout << "Invalid employee name\n";
                discardLine();
                continue;
            }
            Employee* employee = findEmployee(employees, count, name);
            if (!employee) {
                std::cout << "No one has a name like " << name << '\n';
                discardLine();
            } else if (readEmployee(name, age, country, job)) {
                employee->change(name, age, country, job);
            } else {
                std::cout << "Invalid employee information\n";
                discardLine();
            }
        } else if (std::strcmp(command, "print") == 0) {
            std::cout << "=====print=====\n";
            if (count == 0)
                std::cout << "No employees exist\n";
            for (int i = 0; i < count; ++i)
                printEmployee(*employees[i]);
        } else if (std::strcmp(command, "exit") == 0) {
            break;
        } else {
            std::cout << "Wrong command. Try again.\n";
            discardLine();
        }
    }

    for (int i = 0; i < count; ++i)
        delete employees[i];
}
