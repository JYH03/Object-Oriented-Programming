// 4차 과제 3번: 기존 프로그램의 오류를 점검한 수정본
#include "oopstd.h"

struct
{
	char name[40];
	int age;
}person,person_copy;

int main()
{
	int i;
	double n;
	char str1[] = "almost every programmer should know memset!";
	char myname[] = "Pierre de Fermat";
	char key[] = "apple";
	char buf[80];
	char str2[][5] = { "R2D2","C3PO","R2A6" };
	char str3[] = "Sample string";
	char str4[40];
	char str5[40];
	char arr1[] = "To be or not to be";
	char arr2[40];
	char arr3[40];
	char szinput[256];
	char buffer1[256];
	char buffer2[256];
	
	memset(str1, '-', 6);
	puts(str1);

	oopstd::memset(str1, '-', 6);
	puts(str1);
	
	memcpy(person.name, myname, strlen(myname) + 1);
	person.age = 46;
	memcpy(&person_copy, &person, sizeof(person));
	printf("person_copy: %s, %d\n", person_copy.name, person_copy.age);

	oopstd::memcpy(person.name, myname, strlen(myname) + 1);
	person.age = 46;
	oopstd::memcpy(&person_copy, &person, sizeof(person));
	printf("person_copy: %s, %d\n", person_copy.name, person_copy.age);
	
	do
	{
		printf("Guess my favorite fruit? ");
		fflush(stdout);
		scanf("%79s", &buf);
	} while (strcmp(key, buf) != 0);
	puts("Correct answer!");

	do
	{
		printf("Guess my favorite fruit? ");
		fflush(stdout);
		scanf("%79s",& buf);
	} while (oopstd::strcmp(key, buf) != 0);
	puts("Correct answer!");
	
	puts("Looking for R2 astromech droids...");
	for (i = 0; i < 3; i++)
	{
		if (oopstd::strncmp(str2[i], "R2xx", 2) == 0)
			printf("found %s\n", str2[i]);
	}

	puts("Looking for R2 astromech droids...");
	for (i = 0; i < 3; i++)
	{
		if (strncmp(str2[i], "R2xx", 2) == 0)
			printf("found %s\n", str2[i]);
	}
	
	oopstd::strcpy(str4, str3);
	oopstd::strcpy(str5, "copy successful");
	printf("str3: %s\nstr4: %s\nstr5: %s\n", str3, str4, str5);

	strcpy(str4, str3);
	strcpy(str5, "copy successful");
	printf("str3: %s\nstr4: %s\nstr5: %s\n", str3, str4, str5);
	
	oopstd::strncpy(arr2, arr1, sizeof(arr2));
	oopstd::strncpy(arr3, arr2, 5);
	arr3[5] = '\0';
	puts(arr1);
	puts(arr2);
	puts(arr3);

	strncpy(arr2, arr1, sizeof(arr2));
	strncpy(arr3, arr2, 5);
	arr3[5] = '\0';
	puts(arr1);
	puts(arr2);
	puts(arr3);
	
	printf("Enter a sentence: ");
	scanf("%s", &szinput);
	printf("The sentence entered is %u characters long.\n", (unsigned)oopstd::strlen(szinput));

	printf("Enter a sentence: ");
	scanf("%s", &szinput);
	printf("The sentence entered is %u characters long.\n", (unsigned)strlen(szinput));
	
	printf("Enter a number: ");
	cin >> buffer1;
	i = oopstd::atoi(buffer1);
	printf("The value entered is %d. Its double is %d.\n", i, i * 2);

	printf("Enter a number: ");
	cin >> buffer1;
	i = atoi(buffer1);
	printf("The value entered is %d. Its double is %d.\n", i, i * 2);
	
	printf("Enter a number: ");
	cin >> buffer2;
	n = oopstd::atof(buffer2);
	printf("The value entered is %f.\n", n);

	printf("Enter a number: ");
	cin >> buffer2;
	n = atof(buffer2);
	printf("The value entered is %f.\n", n);
}
