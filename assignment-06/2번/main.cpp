// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

class Student {
    char *name;
    int age;
    char *class_name;
    Student(const Student &) = delete;
    Student &operator=(const Student &) = delete;

  public:
    Student() : Student("", 0, "") {}
    Student(const char *n, int a, const char *c) : name(nullptr), age(a), class_name(nullptr) {
        name = new char[strlen(n) + 1];
        try {
            class_name = new char[strlen(c) + 1];
        } catch (...) {
            delete[] name;
            throw;
        }
        strcpy(name, n);
        strcpy(class_name, c);
    }
    ~Student() {
        delete[] name;
        delete[] class_name;
    }
    void print() const {
        cout << "Name: " << name << endl
             << "Age: " << age << endl
             << "Class: " << class_name << endl
             << "----------" << endl;
    }
    const char *getName() const { return name; }
    const char *getClassName() const { return class_name; }
};

class School {
    Student *student_list[100];
    int size;
    School(const School &) = delete;
    School &operator=(const School &) = delete;

  public:
    School() : student_list{}, size(0) {}
    ~School() {
        for (int i = 0; i < size; ++i)
            delete student_list[i];
    }
    void addStudent(const char *name, int age, const char *class_name) {
        if (size == 100) {
            cerr << "Student list is full" << endl;
            return;
        }
        student_list[size++] = new Student(name, age, class_name);
    }
    void sortByNames() {
        for (int i = 0; i < size; ++i)
            for (int j = i + 1; j < size; ++j)
                if (strcmp(student_list[i]->getName(), student_list[j]->getName()) > 0) {
                    Student *temp = student_list[i];
                    student_list[i] = student_list[j];
                    student_list[j] = temp;
                }
    }
    void printAll() const {
        cout << "=====print_all=====" << endl;
        for (int i = 0; i < size; ++i)
            student_list[i]->print();
    }
    void printClass(const char *class_name) const {
        cout << "=====print_class=====" << endl;
        int count = 0;
        for (int i = 0; i < size; ++i)
            if (strcmp(student_list[i]->getClassName(), class_name) == 0) {
                student_list[i]->print();
                ++count;
            }
        cout << "Number of classmates: " << count << endl;
    }
};
int main() {
    School school;
    char command[32];
    while (cin.width(32), cin >> command) {
        if (strcmp(command, "new_student") == 0) {
            char name[50], class_name[50];
            int age;
            cin.width(50);
            if (!(cin >> name >> age))
                break;
            cin.width(50);
            if (!(cin >> class_name))
                break;
            school.addStudent(name, age, class_name);
        } else if (strcmp(command, "sort_by_name") == 0)
            school.sortByNames();
        else if (strcmp(command, "print_all") == 0)
            school.printAll();
        else if (strcmp(command, "print_class") == 0) {
            char class_name[50];
            cin.width(50);
            if (!(cin >> class_name))
                break;
            school.printClass(class_name);
        } else if (strcmp(command, "exit") == 0)
            break;
    }
}
