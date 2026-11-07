// 01반_02반_2022202078_조영훈 1-1주차 3번.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int GCD(int x, int y);									//최대공약수를 구하는 함수
long long int LCD(long long int x, long long int y);	//최소공배수를 구하는 함수 값 초과를 고려해 long long int


int main()
{
	int x, y;
	cout << "x, y: ";				//최대공약수, 최소공배수를 구할 값 x,y를 저장할 변수 선언
	cin >> x >> y;
	if (x < y) swap(x, y);			//입력 받은 두 값중 더 큰 수를 x에 저장
	cout << "GCD is " << GCD(x, y) << endl;		//최대공약수 출력
	cout << "LCD is " << LCD(x, y) << endl;		//최소공배수 출력
}

int GCD(int x, int y)
{
	if (y == 0)					//y가0이면 x가 최대공약수가 됨
		return x;
	return GCD(y, x % y);		//재귀함수를 이용해서 (x,0) 형식이 나올 때까지 반복 x와 y의 최대공약수는 y와 x%y의 최대공약수와 같음
}

long long int LCD(long long int x, long long int y)
{
	return x * y / GCD(x, y);		//최소공배수는 두 값의 곱을 최대공약수로 나눈 것
}