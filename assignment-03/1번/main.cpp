// 3차 과제 1번: 기존 프로그램의 오류를 점검한 수정본
#include <iostream>
#include <cmath>
#define PI 3.141592
using namespace std;
int main()
{
	int i, j, degree, Coordinate[3];
	double Result[3] = {};

	cout << "Degrees: ";
	cin >> degree;													
	cin.ignore();
	cout << "Coordinate: ";											
	cin >> Coordinate[0] >> Coordinate[1] >> Coordinate[2];
	cin.ignore();
	double S = round(sin(degree * PI / 180)*1000000)/1000000;			
	double C = round(cos(degree * PI / 180) * 1000000) / 1000000;		

	double T1[3][3] = { {-C,S,0},{S,C,0},{0,0,0} };						
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			Result[i] = Result[i] + T1[i][j] * Coordinate[j];			
		}
		cout << Result[i] << " ";										
	}
	return 0;
}
