#pragma once

class Employee {
public:
    Employee() noexcept;
    Employee(const char* name, int age, const char* country, const char* job);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    ~Employee();

    bool isNameCorrect(const char* name) const;
    void print() const;
    void change(const char* name, int age, const char* country, const char* job);

private:
    char* name;
    int age;
    char* country;
    char* job;
};
