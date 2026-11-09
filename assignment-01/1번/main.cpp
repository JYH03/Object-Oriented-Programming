// 1차 과제 1번: 기존 프로그램의 오류를 점검한 수정본
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void maker(int N, unsigned char pyramid[640][640]); 


int main()
{
	unsigned char K;
	int i, j, N;
	unsigned char pyramid[640][640] = {
		{' ',' ','$',' ',' '},
		{' ','$',' ','$',' '},
		{'$','$','$','$','$'}				
	};
	cout << "input: ";
	cin >> K;								
	N = K - '0';
	if (N < 1 || N > 7) { cerr << "Invalid input" << endl; return 1; }								
	int n = pow(2, N-1);					

	if (N > 1)								
	{
		maker(N, pyramid);					
		for (i = 0; i < 3*n	; i++)			
		{
			for (j = 0; j <6*n-1.; j++)		
			{
				cout << pyramid[i][j];		
			}
			cout << endl;
		}
	}

	else
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 5; j++)
			{
				cout << pyramid[i][j];		
			}
			cout << endl;
		}
	}

}

void maker( int N, unsigned char pyramid[640][640])
{
	int i, j, k,n,m,floor;
	unsigned char matrix[640][640];					

	for (i = 0; i < 3 * (pow(2,N-1)); i++)			
	{
		for (j = 0; j < 6 * (pow(2, N - 1)) - 1; j++)
		{
			matrix[i][j] = ' ';						
		}
	}

	for (k = 2; k <= N ; k++)						
	{
		n = pow(2, k - 1);							
		m = pow(2, k - 2);							
		floor = 6 * m - 1;							

		for (i = 0; i < n / 2 * 3; i++)
		{
			for (j = 0; j < floor; j++)
			{
				matrix[i][(floor + 1) / 2 + j] = pyramid[i][j];			
			}
		}

		for (i = n / 2 * 3; i < 3 * n; i++)
		{
			for (j = 0; j < floor; j++)
			{
				matrix[i][j] = pyramid[i - (n / 2 * 3)][j];				
				matrix[i][(floor +1) + j] = pyramid[i-(n/2*3)][j];		
			}
		}

		for (i = 0; i < 3 * n; i++)
		{
			for (j = 0; j < 6 * n - 1; j++)
			{
				pyramid[i][j] = ' ';							
				pyramid[i][j] = matrix[i][j];				
				matrix[i][j] = ' ';
			}
		}
	}
}
