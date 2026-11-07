#include "Employee.h"
Empoloyee::Empoloyee()
{
	//대충 초기화 내용
}
Empoloyee::Empoloyee(char* name, int age, char* country, char* job)
{
		Empoloyee::name = name;
		Empoloyee::age = age;
		Empoloyee::country = country;
		Empoloyee::job = job;
}
void Empoloyee::change(char* name, int age, char* country, char* job)
{
	
}
void Empoloyee::print()
{
	cout << "Name: " << name << endl << "Age: " << age << endl << "Country: " << country << endl << "Job: " << job << endl;
	cout
}
void link::make()
{
	ptr = new Empoloyee;
	if (head == nullptr)
	{
		head = tail = ptr;
		head->pNext = nullptr;
	}
	else
	{
		tail->pNext = ptr;
		tail = ptr;
		tail->pNext = NULL;
	}
}
void link::movedata()
{
	tail->
}