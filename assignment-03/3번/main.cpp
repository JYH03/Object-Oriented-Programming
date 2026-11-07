// 01반_02반_2022202078_조영훈 1-3주차 3번.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	char Num[30] = { '\0' };				//입력받을 수를 저장할 char형 배열 변수 선언
	int  num = 0, input, output;		//각각 char로 받은 수를 int형으로 바꿔 저장할 변수, 입력받은 수의 진수, 출력할 진수
	int cnt = 0, i, tmp = 0, k = 0;		//각각 출력할 char형 배열의 길이, 반복문 용 변수, n의 제곱수를 저장할 변수, n의 k제곱을 표현할 변수
	cout << "Input: ";
	cin >> Num >> input >> output;		
	int L = strlen(Num);			//입력받은 길이 저장
	if (input == 10)				//10진수가 입력되었으면
	{
		num = atoi(Num);			//그대로 10진수의 형태로 저장
	}
	else if (input == 2)			//2진수가 입력되었으면
	{
		for (i = 0; i < L; i++)
		{
			num += (Num[i] - '0') * pow(2, L - i - 1);		//10진수로 변경 각 자리 수는 2의L-i-1제곱 만큼의 값을 가지고있음
		}
	}
	else if (input == 8)									//8진수가 입력되었으면
	{
		for (i = 0; i < L; i++)
		{
			num += (Num[i] - '0') * pow(8, L - i - 1);		//10진수로 변경 각 자리 수는 8의L-i-1제곱 만큼의 값을 가지고있음
		}
	}
	else if (input == 16)			//16진수가 입력되었으면
	{
		for (i = 0; i < L; i++)
		{
			if (Num[i] - '9' <= 0)						//0~9가 입력되면 
			{
				num += (Num[i] - '0') * pow(16, L - i - 1);		//10진수로 변경 각 자리 수는 16의L-i-1제곱 만큼의 값을 가지고있음
			}
			else										//A~F가 입력되면
			{
				num += (Num[i] - 55) * pow(16, L - i - 1);		////10진수로 변경 각 자리 수는 16의L-i-1제곱 만큼의 값을 가지고있음
			}
		}
	}

	if (output == 10)			//출력이 10진수 이면
	{
		cout << num;			//10진수 그대로 출력
	}
	else if (output == 2)		//출력이 2진수 이면
	{
		while (num > 0)						
		{
			Num[cnt] = num % 2 + '0';	//각 자리 수를 2로 나눈 나머지를 저장
			num = num / 2;				
			cnt++;
		}
		for (i = cnt - 1; i >= 0; i--)
		{
			cout << Num[i];				//가장 마지막에 나눈 나머지가 맨 앞으로 오기 때문에 반대로 출력
		}
	}
	else if (output == 8)		//출력이 8진수 이면
	{
		while (1)		
		{
			tmp = pow(8, k+1);				//8의 k+1제곱이 num보다 크면 8의 k제곱으로 나누어주면 됨 
			if (tmp > num)					//tmp(8의 k+1제곱)이 num보다 크면 탈출
				break;
			k++;							//k값을 증가시킴
		}
		while (k>-1)					
		{
			tmp = pow(8, k);				
			Num[cnt] = (num / tmp)+'0';			//8의 k제곱으로 나눈 값을 배열에 저장
			num = num % tmp;					
			cnt++;
			k--;								//k값을 감소 시킴(각 자리수가 맨 앞부터 8의 k제곱과의 곱이기 때문에 맨 앞이 8의k제곱이면 그 다음자리는 8의 k-1제곱)
		}
		for (i = 0; i < cnt; i++)
		{
			cout << Num[i];						//출력
		}
	}
	else if (output == 16)						//출력이 16진수 이면
	{
		tmp = pow(16, 1);
		while (1)						
		{
			tmp = pow(16, k+1);					//16의 k+1제곱이 num보다 크면 16의 k제곱으로 나누어주면 됨 
			if (tmp > num)						//tmp(16의 k+1제곱)이 num보다 크면 탈출
				break;
			k++;								//k값을 증가시킴
		}
		while (k>-1)
		{
			tmp = pow(16, k);
			if (num / tmp < 10)							//0~9일 때
			{
				Num[cnt] = (num / tmp) + '0';			//16의 k제곱으로 나눈 값을 배열에 저장
			}
			else
			{	
				Num[cnt] = (num / tmp) + 55;			//16의 k제곱으로 나눈 값을 배열에 저장
			}
			num = num % tmp;
			cnt++;
			k--;								//k값을 감소 시킴(각 자리수가 맨 앞부터 16의 k제곱과의 곱이기 때문에 맨 앞이 16의 k제곱이면 그 다음자리는 16의 k-1제곱)
		}
		for (i = 0; i < cnt; i++)
		{
			cout << Num[i];					//출력
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
