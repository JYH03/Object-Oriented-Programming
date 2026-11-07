// 01반_02반_2022202078_조영훈 1-2주차 3번.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
	int N, i = 0, len, j, k, cnt = 0, ret, a = 0, b = 0, c = 0, l = 0, q = 0, m = 0, p = 0, s = 0;
	char data[10][100], filename[100], inputword[10][100], print[10][100] = { 0 };
	cout << "input file name: ";
	cin >> filename >> N;
	ifstream fin;
	fin.open(filename);
	if (!fin)
	{
		cout << "no" << std::endl;
	}

	while (!fin.eof())
	{
		fin.getline(data[i], 100);
		i++;
		cnt++;										//파일에서 입력받은 문자열의 수 카운트
	}

	for (i = 0; i < N; i++)							//입력한 문자열에 대해
	{
		cin >> inputword[i];
		len = strlen(inputword[i]);
		for (j = 0; j < cnt; j++)					//파일의 문자열에 대해
		{
			m = 0;
			b = 0;
			a = 0;
			l = 0;
			c = 0;
			q = 0;
			s = 0;
			p = 0;
			ret = strlen(data[j]);
			for (k = 0; k < len; k++)				//파일의 문자열의 문자
			{
				if (inputword[i][k+a] == '*')			// *을 입력받으면
				{
					p = 1;									//*이 나왔음을 알리는 키
					if (inputword[i][k + a + 1] == '*')		//*다음도 *이면
					{
						s++;								//*이 연속해서 몇번 나오는지 카운트
						continue;
					}
					if (inputword[i][k + a + 1] == '?')		//*다음 ?가 나오면
					{
						while (inputword[i][k + a + 1] == '?')			//?가 연속으로 나올때
						{
							a++;					//?개수 카운트
						}
						if (inputword[i][k + a + 1] == '*')			//?다음이 *이면 기존 ?처리 처럼 다음 검사로 넘어감
							continue;
					}
					if (inputword[i][k + 1 + a] != '\0')			//다음으로 오는 글자가 \0이 아니면
					{
						while (inputword[i][k + 1 + a] != data[j][k+ m])		//입력받은 값은 *다음으로오는 ?개수 +1 부터 data파일 속 문장의 k번째부터 검사 진행(m)
						{
							if (data[j][k + m + 1] == '\0')						//파일 속 문장이 먼저 끝나면
							{	
								l = 1;											//출력 x
								break;
							}
							m++;												//그렇지 않으면 파일 속 문장 검사를 진행
						}
						m -= 1;													//위치 k+a의 1을 기준으로 m을 카운트 했기 때문에 마지막에 -1을 해서 위치를 맞춰줌
						continue;
					}
					else														//\0이 나왔을 경우
					{
						for (int x = 0; x < ret; x++)							//출력
							cout << data[j][x];
						cout << endl;
						l = 1;
					}
				}

				else if (inputword[i][k+a] == '?')				//?를 입력받으면
				{
					c++;										//?개수 카운트
					if (c > ret)
					{
						l = 1;
						break;
					}
					if (inputword[i][k +a+ 1] != '\0')			
					{
						continue;							//?다음이 \0이 아니면 다음 글자로 넘어감
					}
					else									//\0이면 
					{
						c += a;								//*에서 센 ? 개수 포함
						if (p == 1)							//*이 나왔음을 알리는 키
							m += 1;							//m의 개수를 정상적으로 맞춤
						if (c + q + m == ret)				//?의 개수 + 같은 문자들의 개수 + *이 덮어쓴 글자들의 수가 파일의 길이와 같다면
						{
							for (int x = 0; x < ret; x++)		//출력
								cout << data[j][x];
							cout << endl;
						}
						l = 1;
					}
				}

				if (inputword[i][k+a] == data[j][k + m])		//두 글자를 비교해서 같으면
				{
					q++;										//글자 수 카운트
					continue;
				}
				else											//그렇지 않으면
				{
					l = 1;										//출력을 막는 키
					break;
				}
			}
			if (len == k || (inputword[i][k + 1] == '\0' && l == 0))		//검사가 끝까지 진행되었을 때
			{
				for (int x = 0; x < ret; x++)
					cout << data[j][x];										//출력
				cout << endl;
			}
		}
		cout << endl;
	}
	fin.close();
}