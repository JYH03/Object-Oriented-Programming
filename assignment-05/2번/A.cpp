// 생성자와 소멸자에서 객체의 값을 출력한다.
#include "A.h"

A::A(double n)												
{
	N = n;													
	cout << "Class A is created with " << N << endl;		
}

A::~A()														
{
	cout << "Class A is destroyed with " << N << endl;		
}