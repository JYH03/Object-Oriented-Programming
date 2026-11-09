// 5차 과제 1번: 기존 프로그램의 오류를 점검한 수정본
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
// 배열 명령에서 필요한 문자열 비교와 정수 변환을 직접 수행한다.
int compareText(const char* a, const char* b, int limit = -1) {
    int i=0;
    while ((limit<0 || i<limit) && a[i] && a[i]==b[i]) ++i;
    if (limit>=0 && i==limit) return 0;
    return static_cast<unsigned char>(a[i])-static_cast<unsigned char>(b[i]);
}
int parseNumber(const char* s) {
    int i=0, value=0;
    while (s[i]==' ' || s[i]=='\t') ++i;
    while (s[i]>='0' && s[i]<='9') { value=value*10+(s[i]-'0'); ++i; }
    return value;
}
int main()
{
	int i = 0, j, k = 0, cnt[2] = { 0, }, word, start = 0, num;
	char arr[100000], order[50];
	cin.getline(arr, 100000, '\n');
	while (1)
	{
		cin >> order;					
		
		if (compareText(order, "arr") == 0)
		{
			cout << arr << endl;					
		}
		
		else if (compareText(order, "arr", 3) == 0)
		{
			
			while (order[k] != '\0')
			{
				
				while ((order[k] < '0' || order[k] > '9')&&order[k] !='\0')
				{
					order[k] = ' ';				
					k++;
				}
				if (order[k] == '\0')
					break;
				num = parseNumber(order);		
				while (order[k] >= '0' && order[k] <= '9')
				{
					order[k] = ' ';				
					k++;
				}
				cnt[1] = cnt[0];
				cnt[0]++;			
				word = -1;
				i = start;			
				
				while (word != num + 1)
				{
					
					if (arr[i] == '[')			
					{
						cnt[1]++;				
						if (cnt[0] != cnt[1])	
						{
							i++;
							while (cnt[0] != cnt[1])	
							{
								if (arr[i] == '[')		
									cnt[1]++;
								else if (arr[i] == ']')	
									cnt[1]--;
								i++;
							}
						}
						else					
						{
							word++;				
							if (word == num)	
								start = i + 1;	
						}
					}
					if (arr[i] == ']')			
					{
						word++;						
					}
					
					if (arr[i] == ',')	
					{
						word++;			
						if (word == num)	
							start = i + 1;	
					}
					i++;			
				}
			}
			for (j = start; j < i - 1; j++)
			{
				cout << arr[j];					
			}
			cout << endl;
			
			i = 0;
			k = 0;
			cnt[0] = 0;
			cnt[1] = 0;
			start = 0;
		}
		
		else
			break;		
	}
	return 0;
}
