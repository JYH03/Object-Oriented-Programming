// 01반_02반_2022202078_조영훈 1-2주차 1번.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int i, j, N, x =-1;							//반복문을위한 변수 i,j 문자의 길이를 저장할 변수 N, 새로만든 배열의 위치를 정할 변수 x
	char k, cnt = '0';							//문자열을 검사할 때 기준이 될 문자를 저장할 변수 k, 검사를 진행해서 같은 수의 갯수를 저장할 변수 cnt
	char first[101]={0}, second[101] = {0};			//각각 첫 번째, 두 번째 숫자를 받을  char배열 변수 first, second

	cout << "Input first number: ";
	cin >> first;
	cout << "Input second number: ";
	cin >> second;

	strcat(first, second);						//문자열 붙이는 함수 strcat
	N = strlen(first);							//문자열의 길이를 세는 함수 strlen

	for (i = 0; i < N; i++)
	{
		x++;									//0부터 x카운트 (첫 번째 숫자는 중복이 되지 않아 차감되지 않음)
		k = first[i];
		if (k - 'a' == 0)						//중복되는 수를 만났을 경우
		{
			x--;								//x 카운트 차감
			continue;							//중복이기 때문에 cnt카운트 및 배열에 저장을 건너 뜀
		}
		for (j = 0; j < N; j++)
		{
			if (k == first[j])					//검사할 문자와 동일한 문자열의 문자를
			{
				cnt++;							//cnt카운트 한 후
				first[j] = 'a';					//문자 'a'로 변경 
			}
		}

		second[2 * x] = k;						//배열의 짝수번째에는 차례대로 검사한 문자 입력(검사 안한 경우를 생각해 i가 아닌 x사용)
		second[2 * x+1] = cnt;					//배열의 홀수번째에는 검사한 문자와 동일한 문자들의 갯수 입력(검사 안한 경우를 생각해 i가 아닌 x사용)
		cnt = '0';								//다음 검사할 문자와 동일한 문자들의 갯수 카운트를 위해 cnt카운트 초기화
	}

	N = strlen(second);							//최종 완성된 문자열의 길이를 변수 N에 입력
	for (i = 0; i < N; i++)						//문자열 출력
		cout << second[i];
}


