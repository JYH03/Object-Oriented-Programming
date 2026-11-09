// 1차 과제 3번: 기존 프로그램의 오류를 점검한 수정본
#include <iostream>
using namespace std;

// 두 정수의 값을 직접 교환한다.
void swapValues(int& left, int& right) { int temp = left; left = right; right = temp; }

int GCD(int x, int y);									
long long int LCD(long long int x, long long int y);	


int main()
{
	int x, y;
	cout << "x, y: ";				
	cin >> x >> y;
	if (x < y) swapValues(x, y);			
	cout << "GCD is " << GCD(x, y) << endl;		
	cout << "LCD is " << LCD(x, y) << endl;		
}

int GCD(int x, int y)
{
	if (y == 0)					
		return x;
	return GCD(y, x % y);		
}

long long int LCD(long long int x, long long int y)
{
	if (x == 0 || y == 0) return 0;
	return x / GCD(x, y) * y;		
}
