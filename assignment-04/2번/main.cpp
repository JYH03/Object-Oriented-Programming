// 01반_02반_2022202078_조영훈 2-1주차 2번.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

typedef struct Queue
{
	int xpos;
	int ypos;
	int check;
	Queue* next;
}Queue;
int main()
{
	int l;
	Queue node;
	bool visit[30][30] = { false, };
	int x1, x2, y1, y2, p, q, i, j, X, Y;
	int changeX[] = { -1,1,0,0 };
	int changeY[] = { 0,0,-1,1 };
	char maze[30][30] = { 1, };
	Queue* head, * tail, * ptr;
	cin >> p >> q;
	for (i = 0; i < p; i++)
	{
		for (j = 0; j < q; j++)
		{
			cin >> maze[i][j];					//p와 q의 범위 만큼 값 입력
		}
	}
	cin >> x1 >> y1 >> x2 >> y2;				//시작좌표와 끝 좌표 입력
	x1--;
	x2--;
	y1--;
	y2--;						//배열에 맞게 조정
	//시작 좌표를 큐에 저장
	visit[y1][x1] = true;						//시작점 true로 변경
	ptr = new Queue;							//메모리 할당
	ptr->xpos = x1;								//시작 x좌표를 입력
	ptr->ypos = y1;								//시작 y좌표를 입력
	ptr->check = 1;								//길의 최단거리 입력
	head = tail = ptr;							//큐의 시작과 끝을 처음 할당된 메모리 주소 저장
	ptr->next = NULL;
	while (1)
	{
		l = head->check + 1;						//다음 칸은 전칸 길이+1
		x1 = head->xpos;						//큐의 시작의 x좌표를 입력받음
		y1 = head->ypos;						//큐의 시작의 y좌표를 입력받음
		if (x1 == x2 && y1 == y2)				//두 좌표가 같으면 
		{
			break;								//탐색 중지
		}
		for (i = 0; i < 4; i++)
		{
			X = x1 + changeX[i];				//x좌표의 -1,+1
			Y = y1 + changeY[i];				//y좌표의 -1,+1
			if (Y < 30 && Y >= 0 && X < 30 && X >= 0 && maze[Y][X] == '0' && visit[Y][X] != true)	//맵 크기보다 작고 0이며 방문한 곳이 아닐 때
			{
				ptr = new Queue;			//동적할당하고 주소를 저장
				ptr->xpos = X;				//주소에 if조건식을 만족하는 x좌표 저장
				ptr->ypos = Y;				//주소에 if조건식을 만족하는 y좌표 저장
				ptr->check = l;				//시작점 부터 이동한 칸수 
				tail->next = ptr;			//ptr의 주소를 tail이 가리키는 주소의 포인터에 저장
				tail = ptr;					//ptr의 주소를 tail이 저장
				tail->next = NULL;			//tail의 주소의 포인터가 NULL을 가리키게 함 
				visit[Y][X] = true;			//방문한 곳은 true로 변경
			}
		}
		Queue* del = head;					//head 삭제용 변수, head의 주소를 받음
		head = head->next;					//head를 head 주소의 포인터가 가리키는 주소로 이동
		delete del;							//del의 주소를 해제함
	}
	cout << l - 1;							//최단거리 출력(탈출 직전 +1 했기 때문에 -1)
	ptr = head;								
	while (ptr != NULL)						//메모리 해제
	{
		head = ptr;
		ptr = ptr->next;
		delete head;
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
