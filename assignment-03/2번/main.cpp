// 01반_02반_2022202078_조영훈 1-3주차 2번.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;
int GCD(int x, int y)			//최대공약수를 구하는 함수
{
	if (y == 0)
		return x;
	GCD(y, x % y);
}

int main()
{
	int cnt[2] = {0},x,y,k,P,nine=9,ncnt=1;
	double Vs, R1, R2, RL,I, Vout,VL,IRL,Power,RR, Vint;
	cout << "Vs: ";
	cin >> Vs;
	cout << "R1: ";
	cin >> R1;
	cout << "R2: ";
	cin >> R2;
	cout << "R(Load): ";
	cin >> RL;
	if (RL == 0)
	{
		I = Vs / (R1 + R2);
		Vout = I*R2;
		y = Vs * R2;				//분수 y/x의 분자
		x = R1 + R2;				//분수 y/x의 분모
		if (x < y)					//최대 공약수를 구하기 전 더 큰 수가 먼저오게 
		{
			swap(x, y);				//교환
			k = GCD(x, y);			//최대공약수 구하기
			swap(x, y);				//다시 원래 교환
		}
		else
		{
			k = GCD(x, y);			
		}
		x = x / k;					//분모를 최대공약수로 나누어서 기약분수로 만듬
		y = y / k;					//분자를 최대공약수로 나눔
		while (x % 2 == 0)			//약수중 2가있으면
		{
			x = x / 2;				//없애기
			cnt[0]++;				//2의p제곱 구하기
		}
		while (x % 5 == 0)			//약수중 5가있으면
		{
			x = x / 5;				//없애기
			cnt[1]++;				//5의q제곱 구하기
		}
		if (x == 1)					//소인수가 2와 5로 이루어져있었다면 -> 유한소수
		{
			Vout = Vout * 100;		//소수로 출력될 경우 2자리 수까지 출력하기 위해 100을 곱한 후
			Vout=round(Vout)/100;	//반올림
			cout << "Vout: " << Vs * R2 << '/' << (R1 + R2) << " = " << Vout;		//출력
		}
		else if(cnt[0]==0&&cnt[1]==0)		//분모의 소인수에 2와 5가 없이 어떤 n값만 있다면 -> 순순환소수
		{
			//순환마디 길이 구하기
			while (nine % x != 0)					//9로만 이루어진 수로 맞추기
			{
				nine = nine * 10 + 9;				//9의 개수 늘리기 99,999,...
				ncnt++;								//9의 개수
			}
			Vint = (Vout - (int)Vout);				//정수 부분 삭제
			Vint = Vint * pow(10, ncnt);			//9의 개수만큼 소수점 구하기 -> 순환마디의 길이 만큼 정수로 이동
			cout << "Vout: " << Vs * R2 << '/' << (R1 + R2) << " = " << (int)Vout<<"("<<(int)Vint<<")";			//출력
		}
		else									//분모의 소인수에 2와 5가 있었으며 어떤 n이 있으면 -> 홀순환소수
		{
			if (cnt[0] > cnt[1])				//홀순환소수에서 순환마디의 시작지점 = 2^p,5^q 에서 p와 q 중 더 큰 수+1부터 시작
				P = cnt[0];						//p가 더클 때
			else
				P = cnt[1];						//q가 더 클 때
			//순환마디 길이 구하기
			while (nine % x != 0)					//9로만 이루어진 수로 맞추기
			{
				nine = nine * 10 + 9;				//9의 개수 늘리기 99,999,...
				ncnt++;								//9의 개수
			}
			Vint = (Vout - (int)Vout);				//정수 부분 삭제
			Vint = Vint * pow(10, P);				//순환마디가 소수점 첫째 자리까지 오게
			Vint = (Vout - (int)Vout);				//정수부분 다시 삭제
			Vint = Vint * pow(10, ncnt);			//9의 개수만큼 소수점 구하기-> 순환마디의 길이 만큼 정수로 이동
			cout << "Vout: " << Vs * R2 << '/' << (R1 + R2) << " = " << (int)Vout << "(" << (int)Vint << ")";		//출력
		}
	}

	else
	{
		IRL = R2 / (R2 + RL);
		RR = R2 * RL / (R2 + RL);			//R2||RL
		I = Vs / (R1 + RR);
		Vout = I * RR;
		IRL = IRL * I;
		VL = IRL * RL;
		Power = (Vs * I) / (VL * IRL);
		y = Vs * R2 * RL;						//분수 y/x의 분자
		x = (R1 + RR) * (RL + R2);				//분수 y/x의 분모
		if (x < y)
		{
			swap(x, y);							//교환
			k = GCD(x, y);						//최대공약수 구하기
			swap(x, y);							//다시 교환
		}
		else
		{
			k = GCD(x, y);
		}
		x = x / k;								//분모를 최대공약수로 나누어 기약분수로 만듬
		y = y / k;								//분자를 최대공약수로 나눔
		while (x % 2 == 0)						//약수중 2가있으면
		{
			x = x / 2;							//2로 나누기
			cnt[0]++;							//2의p제곱 구하기
		}
		while (x % 5 == 0)						////약수중 5가있으면
		{
			x = x / 5;							//5로 나누기
			cnt[1]++;							//5의q제곱 구하기
		}
		if (x == 1)								//소인수가 2와 5로 이루어져있었다면 -> 유한소수
		{
			Vout = Vout * 100;		//소수로 출력될 경우 2자리 수까지 출력하기 위해 100을 곱한 후
			Vout = round(Vout) / 100;	//반올림
			cout << "Vout: " << Vs * R2 * RL << '/' << (R1 + RR) * (RL + R2) << " = " << Vout << endl;
			cout << "Load power ratio: ";
			cout << fixed;
			cout.precision(2);				//소수점 2번 째 자리까지
			cout << Power << "%";
		}
		else if (cnt[0] == 0 && cnt[1] == 0)
		{
			//순환마디 길이 구하기
			while (nine % x != 0)					//9로만 이루어진 수로 맞추기
			{
				nine = nine * 10 + 9;				//9의 개수 늘리기 99,999,...
				ncnt++;								//9의 개수
			}
			Vint = (Vout - (int)Vout);				//정수 부분 삭제
			Vint = Vint * pow(10, ncnt);			//9의 개수만큼 소수점 구하기 -> 순환마디의 길이 만큼 정수로 이동
			cout << "Vout: " << Vs * R2 * RL << '/' << (R1 + RR) * (RL + R2) << " = " << (int)Vout << "(" << (int)Vint << ")";
			cout << "Load power ratio: ";
			cout << fixed;
			cout.precision(2);				//소수점 2번 째 자리까지 
			cout << Power << "%";
		}
		else
		{
			if (cnt[0] > cnt[1])				//홀순환소수에서 순환마디의 시작지점 = 2^p,5^q 에서 p와 q 중 더 큰 수+1부터 시작
				P = cnt[0];						//p가 더클 때
			else
				P = cnt[1];						//q가 더 클 때
			//순환마디 길이 구하기
			while (nine % x != 0)					//9로만 이루어진 수로 맞추기
			{
				nine = nine * 10 + 9;				//9의 개수 늘리기 99,999,...
				ncnt++;								//9의 개수
			}
			Vint = (Vout - (int)Vout);				//정수 부분 삭제
			Vint = Vint * pow(10, P);				//순환마디가 소수점 첫째 자리까지 오게
			Vint = (Vout - (int)Vout);				//정수부분 다시 삭제
			Vint = Vint * pow(10, ncnt);			//9의 개수만큼 소수점 구하기-> 순환마디의 길이 만큼 정수로 이동
			cout << "Vout: " << Vs * R2 * RL << '/' << (R1 + RR) * (RL + R2) << " = " << (int)Vout << "(" << (int)Vint << ")";
			cout << "Load power ratio: ";
			cout << fixed;
			cout.precision(2);				//소수점 2번 째 자리까지
			cout << Power << "%";
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
