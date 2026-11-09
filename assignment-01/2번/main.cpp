// 1차 과제 2번: 기존 프로그램의 오류를 점검한 수정본
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float a = 0, b, c;				
	float x1, x2;					

	cout << "이차방정식의 계수 a, b, c를 입력하세요 : ";
	cin >> a >> b >> c;
	while (a == 0)					
	{
		cout << "Unexpected factor of a quadratic term" << endl;	
		cout << "이차방정식의 계수 a, b, c를 입력하세요 : ";
		cin >> a >> b >> c;
	}

	if (pow(b, 2) - 4 * a * c >= 0)
	{
	x1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);		
	x2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);		

	}

	if (pow(b, 2) - 4 * a * c < 0)
		cout << "The equation has no real number solutions.";		
	else if (pow(b, 2) - 4 * a * c == 0)
		cout << "X1,X2: " << x1<<"(double root)";			
	else
	{
		cout << "X1: " << x1 << ","<<endl;					
		cout << "X2: " << x2;
	}
}
