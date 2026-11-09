#include "Employee.h"

#include <cstring>
#include <iostream>

namespace {
const char* emptyIfNull(const char* text) {
    return text ? text : "";
}

char* copyText(const char* text) {
    text = emptyIfNull(text);
    const auto size = std::strlen(text) + 1;
    char* copy = new char[size];
    std::memcpy(copy, text, size);
    return copy;
}

void exchangeText(char*& left, char*& right) noexcept {
    char* previous = left;
    left = right;
    right = previous;
}
}

Employee::Employee() noexcept : name(nullptr), age(0), country(nullptr), job(nullptr) {}

Employee::Employee(const char* initialName, int initialAge, const char* initialCountry, const char* initialJob)
    : Employee() {
    name = copyText(initialName);
    country = copyText(initialCountry);
    job = copyText(initialJob);
    age = initialAge;
}

Employee::Employee(const Employee& other)
    : Employee(other.name, other.age, other.country, other.job) {}

Employee& Employee::operator=(const Employee& other) {
    if (this != &other)
        change(other.name, other.age, other.country, other.job);
    return *this;
}

Employee::~Employee() {
    delete[] name;
    delete[] country;
    delete[] job;
}

bool Employee::isNameCorrect(const char* candidate) const {
    return candidate && std::strcmp(emptyIfNull(name), candidate) == 0;
}

void Employee::print() const {
    std::cout << "Name: " << emptyIfNull(name) << '\n'
              << "Age: " << age << '\n'
              << "Country: " << emptyIfNull(country) << '\n'
              << "Job: " << emptyIfNull(job) << '\n';
}

void Employee::change(const char* newName, int newAge, const char* newCountry, const char* newJob) {
    // 새 정보를 모두 복사한 뒤 기존 문자열의 소유권을 교환한다.
    Employee replacement(newName, newAge, newCountry, newJob);
    exchangeText(name, replacement.name);
    exchangeText(country, replacement.country);
    exchangeText(job, replacement.job);
    age = newAge;
}

