// 01반_02반_2022202078_조영훈 2-1주차 1번.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char order[20];			//명령을 입력 받을 변수
	int stack[128]={};		//스택을 구현할 배열
	int i=0, cnt=0;			//i는 스택에 입력된 값의 개수
	while (1)
	{
		cin >>order;			//명령 입력
		cin.ignore();
		if (strcmp(order, "push")==0)		//push가 입력되면 
		{
			cin >> stack[i];				//stack배열에 값을 저장
			i++;							//다음 배열로 이동
		}
		else if (strcmp(order, "pop")==0)	//pop이 입력되면
		{
			if (i!= 0)						//stack에 1개 이상 값이 있을 때
			{
				cout << stack[i - 1] << endl;	//가장 최근에 저장된 값을 출력 후
				stack[i - 1] = NULL;			//값을 초기화 한 뒤
				i--;						//이전 배열로 이동
			}
		}
		else if (strcmp(order,"top")==0)	//top이 입력되면 
		{
			if(i!=0)						//stack에 1개 이상의 값이 있을 때
			cout << stack[i - 1] << endl;	//가장 마지막에 저장된 값을 출력
		}
		else if (strcmp(order, "print")==0)		//print가 입력되면
		{
			while (cnt!=i)					//stack에 1개 이상 값이 있을 때(값의 개수가 0이면 출력x)
			{
				cout << stack[cnt]<<" ";	//stack에 저장된 모든 값을 출력
				cnt++;						// 값의 개수까지 카운트 하는 변수
			}
			cout << endl;
			cnt = 0;						//값의 개수를 세는 변수
		}
		else if (strcmp(order,"empty")==0)	//empty가 입력되면
		{
			if (i == 0)						//i(stack에 저장된 값의 개수)가 0이면
				cout << "1"<<endl;			//1 출력
			else							//그렇지 않으면
				cout << "0"<<endl;			//0 출력
		}
		else								//주어진 명령외의 다른 입력 및 exit가 입력되면 
			break;							//종료
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
