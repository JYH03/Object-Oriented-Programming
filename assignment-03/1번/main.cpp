// 01반_02반_2022202078_조영훈 1-3주차 1번.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#define PI 3.141592
using namespace std;
int main()
{
	int i, j, degree, Coordinate[3];
	double Result[3] = {};

	cout << "Degrees: ";
	cin >> degree;													//각도 입력
	cin.ignore();
	cout << "Coordinate: ";											//좌표 x,y,z 입력
	cin >> Coordinate[0] >> Coordinate[1] >> Coordinate[2];
	cin.ignore();
	double S = round(sin(degree * PI / 180)*1000000)/1000000;			//100만 -> 6자리부터 반올림 
	double C = round(cos(degree * PI / 180) * 1000000) / 1000000;		//100만 -> 6자리부터 반올림

	double T1[3][3] = { {-C,S,0},{S,C,0},{0,0,0} };						//행렬 T 선언
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			Result[i] = Result[i] + T1[i][j] * Coordinate[j];			//행렬 T와 입력받은 x,y,z 좌표의 행렬곱
		}
		cout << Result[i] << " ";										//출력
	}
	return 0;
}


