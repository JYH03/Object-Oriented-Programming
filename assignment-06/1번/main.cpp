#include "Employee.h"

int main()
{
	int age=0;
	char name[10];
	char country[100];
	char job[100];
	string order;
	Empoloyee node;
	link linknode;
	while (1)
	{
		cin >> order;
		if (order == "insert")
		{
			linknode.make();
			cin >> name >> age >> country >> job;
			Empoloyee Empolyee(name, age, country, job);
		}
		else if (order == "print")
		{
			node.print();
		}
		else if (order == "change")
		{

		}
		else if (order == "find")
		{
			cin >> name;
			node.find(name);
		}
		else
		{
			break;
		}
	}
}

