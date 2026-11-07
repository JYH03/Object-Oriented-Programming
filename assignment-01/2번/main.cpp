// 01반_02반_2022202078_조영훈 1-1주차 2번.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float a = 0, b, c;				//float형 변수 a, b, c(각각 2차방정식의 계수)
	float x1, x2;					//근의 공식으로 구한 두 근을 저장할 변수

	cout << "이차방정식의 계수 a, b, c를 입력하세요 : ";
	cin >> a >> b >> c;
	while (a == 0)					
	{
		cout << "Unexpected factor of a quadratic term" << endl;	//a=0이면 이차방정식이 만족되지 않음으로 문구 출력 후 다시 a값 b값 c값을 입력받음
		cout << "이차방정식의 계수 a, b, c를 입력하세요 : ";
		cin >> a >> b >> c;
	}

	x1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);		//근의 공식으로 구한 첫번 째 근
	x2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);		//근의 공식으로 구한 두 번째 근

	if (pow(b, 2) - 4 * a * c < 0)
		cout << "The equation has no real number solutions.";		//실수근을 가지지 않을 때 문구 출력
	else if (pow(b, 2) - 4 * a * c == 0)
		cout << "X1,X2: " << x1<<"(double root)";			//중근을 가질 때 근 문구와 중근을 출력
	else
	{
		cout << "X1: " << x1 << ","<<endl;					//근의 공식으로 구한 두 근 출력
		cout << "X2: " << x2;
	}
}
