#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void maker(int N, unsigned char pyramid[640][640]); /*시어핀스키 삼각형을 만드는 함수 N은 입력값,
															배열은 시어핀스키 삼각형을 저장할 배열*/

int main()
{
	unsigned char K;
	int i, j, N;
	unsigned char pyramid[640][640] = {
		{' ',' ','$',' ',' '},
		{' ','$',' ','$',' '},
		{'$','$','$','$','$'}				//가장 작은 시어핀스키 삼각형을 2차원 배열에 입력
	};
	cout << "input: ";
	cin >> K;								//입력 값 K
	N = K - '0';								//정수형으로 변경
	int n = pow(2, N-1);					

	if (N > 1)								
	{
		maker(N, pyramid);					//N이 2 이상일 경우 시어핀스키 삼각형을 만드는 함수 호출
		for (i = 0; i < 3*n	; i++)			//N이 입력 됬을 때 높이는 3*2^(N-1)
		{
			for (j = 0; j <6*n-1.; j++)		//N이 입력 됬을 때 너비는 6*2^(N-1) - 1
			{
				cout << pyramid[i][j];		//삼각형 출력
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
				cout << pyramid[i][j];		//1일 경우 그대로 삼각형 출력
			}
			cout << endl;
		}
	}

}

void maker( int N, unsigned char pyramid[640][640])
{
	int i, j, k,n,m,floor;
	unsigned char matrix[640][640];					//시어핀스키 삼각형을 만들기 위해 임시로 최대 크기의 2차원 배열 선언

	for (i = 0; i < 3 * (pow(2,N-1)); i++)			
	{
		for (j = 0; j < 6 * (pow(2, N - 1)) - 1; j++)
		{
			matrix[i][j] = ' ';						//임시 배열 속 값을 공백으로 초기화
		}
	}

	for (k = 2; k <= N ; k++)						//함수를 호출할 수 있는 N의 최솟값 2부터 입력받은 값 N까지
	{
		n = pow(2, k - 1);							//계산을 위한 변수
		m = pow(2, k - 2);							//계산을 위한 변수
		floor = 6 * m - 1;							//시어핀스키 삼각형에서 전체 삼각형이 아닌 가장 큰 세 삼각형 중 하나의 한 변의 길이

		for (i = 0; i < n / 2 * 3; i++)
		{
			for (j = 0; j < floor; j++)
			{
				matrix[i][(floor + 1) / 2 + j] = pyramid[i][j];			//윗 삼각형, 전체 삼각형이 아닌 가장 큰 세 삼각형 중 하나의 한 변의 길이의 반 만큼 띄워서 저장
			}
		}

		for (i = n / 2 * 3; i < 3 * n; i++)
		{
			for (j = 0; j < floor; j++)
			{
				matrix[i][j] = pyramid[i - (n / 2 * 3)][j];				//왼쪽 삼각형, 위 삼각형의 왼쪽 아래 꼭짓점에 왼쪽 삼각형의 윗 꼭짓점이 만나게 하도록 삼각형 저장 
				matrix[i][(floor +1) + j] = pyramid[i-(n/2*3)][j];		//오른쪽 삼각형 위 삼각형의 오른쪽 아래 꼭짓점에 오른쪽 삼각형의 윗 꼭짓점이 만나게 하도록 삼각형 저장 
			}
		}

		for (i = 0; i < 3 * n; i++)
		{
			for (j = 0; j < 6 * n - 1; j++)
			{
				pyramid[i][j] = ' ';							
				pyramid[i][j] = matrix[i][j];				//완성한 시어핀스키 삼각형을 pyramid 배열에 저장
				matrix[i][j] = ' ';
			}
		}
	}
}
