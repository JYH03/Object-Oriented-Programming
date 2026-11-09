// 3차 과제 3번: 기존 프로그램의 오류를 점검한 수정본
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	char Num[30] = { '\0' };				
	int  num = 0, input, output;		
	int cnt = 0, i, tmp = 0, k = 0;		
	cout << "Input: ";
	cin >> Num >> input >> output;		
	int L = strlen(Num);			
	if (input == 10)				
	{
		num = atoi(Num);			
	}
	else if (input == 2)			
	{
		for (i = 0; i < L; i++)
		{
			num += (Num[i] - '0') * pow(2, L - i - 1);		
		}
	}
	else if (input == 8)									
	{
		for (i = 0; i < L; i++)
		{
			num += (Num[i] - '0') * pow(8, L - i - 1);		
		}
	}
	else if (input == 16)			
	{
		for (i = 0; i < L; i++)
		{
			if (Num[i] - '9' <= 0)						
			{
				num += (Num[i] - '0') * pow(16, L - i - 1);		
			}
			else										
			{
				num += (Num[i] - 55) * pow(16, L - i - 1);		
			}
		}
	}

	if (output == 10)			
	{
		cout << num;			
	}
	else if (output == 2)		
	{
		if (num == 0) cout << 0;
		while (num > 0)						
		{
			Num[cnt] = num % 2 + '0';	
			num = num / 2;				
			cnt++;
		}
		for (i = cnt - 1; i >= 0; i--)
		{
			cout << Num[i];				
		}
	}
	else if (output == 8)		
	{
		while (1)		
		{
			tmp = pow(8, k+1);				
			if (tmp > num)					
				break;
			k++;							
		}
		while (k>-1)					
		{
			tmp = pow(8, k);				
			Num[cnt] = (num / tmp)+'0';			
			num = num % tmp;					
			cnt++;
			k--;								
		}
		for (i = 0; i < cnt; i++)
		{
			cout << Num[i];						
		}
	}
	else if (output == 16)						
	{
		tmp = pow(16, 1);
		while (1)						
		{
			tmp = pow(16, k+1);					
			if (tmp > num)						
				break;
			k++;								
		}
		while (k>-1)
		{
			tmp = pow(16, k);
			if (num / tmp < 10)							
			{
				Num[cnt] = (num / tmp) + '0';			
			}
			else
			{	
				Num[cnt] = (num / tmp) + 55;			
			}
			num = num % tmp;
			cnt++;
			k--;								
		}
		for (i = 0; i < cnt; i++)
		{
			cout << Num[i];					
		}
	}
}
