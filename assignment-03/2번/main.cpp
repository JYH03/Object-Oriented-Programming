// 3차 과제 2번: 기존 프로그램의 오류를 점검한 수정본
#include <iostream>
#include <cmath>
using namespace std;

// 두 정수의 값을 직접 교환한다.
void swapValues(int& left, int& right) { int temp = left; left = right; right = temp; }
int GCD(int x, int y)			
{
	if (y == 0)
		return x;
	return GCD(y, x % y);
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
		y = Vs * R2;				
		x = R1 + R2;				
		if (x < y)					
		{
			swapValues(x, y);				
			k = GCD(x, y);			
			swapValues(x, y);				
		}
		else
		{
			k = GCD(x, y);			
		}
		x = x / k;					
		y = y / k;					
		while (x % 2 == 0)			
		{
			x = x / 2;				
			cnt[0]++;				
		}
		while (x % 5 == 0)			
		{
			x = x / 5;				
			cnt[1]++;				
		}
		if (x == 1)					
		{
			Vout = Vout * 100;		
			Vout=round(Vout)/100;	
			cout << "Vout: " << Vs * R2 << '/' << (R1 + R2) << " = " << Vout;		
		}
		else if(cnt[0]==0&&cnt[1]==0)		
		{
			
			while (nine % x != 0)					
			{
				nine = nine * 10 + 9;				
				ncnt++;								
			}
			Vint = (Vout - (int)Vout);				
			Vint = Vint * pow(10, ncnt);			
			cout << "Vout: " << Vs * R2 << '/' << (R1 + R2) << " = " << (int)Vout<<"("<<(int)Vint<<")";			
		}
		else									
		{
			if (cnt[0] > cnt[1])				
				P = cnt[0];						
			else
				P = cnt[1];						
			
			while (nine % x != 0)					
			{
				nine = nine * 10 + 9;				
				ncnt++;								
			}
			Vint = (Vout - (int)Vout);				
			Vint = Vint * pow(10, P);				
			Vint = Vint - (int)Vint;				
			Vint = Vint * pow(10, ncnt);			
			cout << "Vout: " << Vs * R2 << '/' << (R1 + R2) << " = " << (int)Vout << "(" << (int)Vint << ")";		
		}
	}

	else
	{
		IRL = R2 / (R2 + RL);
		RR = R2 * RL / (R2 + RL);			
		I = Vs / (R1 + RR);
		Vout = I * RR;
		IRL = IRL * I;
		VL = IRL * RL;
		Power = (Vs * I != 0) ? (VL * IRL) / (Vs * I) * 100 : 0;
		y = Vs * R2 * RL;						
		x = (R1 + RR) * (RL + R2);				
		if (x < y)
		{
			swapValues(x, y);							
			k = GCD(x, y);						
			swapValues(x, y);							
		}
		else
		{
			k = GCD(x, y);
		}
		x = x / k;								
		y = y / k;								
		while (x % 2 == 0)						
		{
			x = x / 2;							
			cnt[0]++;							
		}
		while (x % 5 == 0)						
		{
			x = x / 5;							
			cnt[1]++;							
		}
		if (x == 1)								
		{
			Vout = Vout * 100;		
			Vout = round(Vout) / 100;	
			cout << "Vout: " << Vs * R2 * RL << '/' << (R1 + RR) * (RL + R2) << " = " << Vout << endl;
			cout << "Load power ratio: ";
			cout << fixed;
			cout.precision(2);				
			cout << Power << "%";
		}
		else if (cnt[0] == 0 && cnt[1] == 0)
		{
			
			while (nine % x != 0)					
			{
				nine = nine * 10 + 9;				
				ncnt++;								
			}
			Vint = (Vout - (int)Vout);				
			Vint = Vint * pow(10, ncnt);			
			cout << "Vout: " << Vs * R2 * RL << '/' << (R1 + RR) * (RL + R2) << " = " << (int)Vout << "(" << (int)Vint << ")";
			cout << "Load power ratio: ";
			cout << fixed;
			cout.precision(2);				
			cout << Power << "%";
		}
		else
		{
			if (cnt[0] > cnt[1])				
				P = cnt[0];						
			else
				P = cnt[1];						
			
			while (nine % x != 0)					
			{
				nine = nine * 10 + 9;				
				ncnt++;								
			}
			Vint = (Vout - (int)Vout);				
			Vint = Vint * pow(10, P);				
			Vint = Vint - (int)Vint;				
			Vint = Vint * pow(10, ncnt);			
			cout << "Vout: " << Vs * R2 * RL << '/' << (R1 + RR) * (RL + R2) << " = " << (int)Vout << "(" << (int)Vint << ")";
			cout << "Load power ratio: ";
			cout << fixed;
			cout.precision(2);				
			cout << Power << "%";
		}
	}
}
