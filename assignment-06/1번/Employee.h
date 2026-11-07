#pragma once
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Empoloyee
{
private:
    int Sequence=1;
    char* name;
    int age;
    char* country;
    char* job;
public:
    Empoloyee* pNext = NULL;
    Empoloyee();
    Empoloyee(char* name, int age, char* country, char* job);
    Empoloyee(Empoloyee &A);
    bool isNameCorrect(char* name);
    void find(char* name);
    void print();
    void change(char* name, int age, char* country, char* job);
    void link();
};
class link
{
public:
    Empoloyee* ptr;
    Empoloyee* head;
    Empoloyee* tail;
    void make();
    void movedata();
};