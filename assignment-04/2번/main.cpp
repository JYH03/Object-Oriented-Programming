// 4차 과제 2번: 기존 프로그램의 오류를 점검한 수정본
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
			cin >> maze[i][j];					
		}
	}
	cin >> x1 >> y1 >> x2 >> y2;				
	x1--;
	x2--;
	y1--;
	y2--;						
	
	visit[y1][x1] = true;						
	ptr = new Queue;							
	ptr->xpos = x1;								
	ptr->ypos = y1;								
	ptr->check = 1;								
	head = tail = ptr;							
	ptr->next = NULL;
	while (head != NULL)
	{
		l = head->check + 1;						
		x1 = head->xpos;						
		y1 = head->ypos;						
		if (x1 == x2 && y1 == y2)				
		{
			break;								
		}
		for (i = 0; i < 4; i++)
		{
			X = x1 + changeX[i];				
			Y = y1 + changeY[i];				
			if (Y < p && Y >= 0 && X < q && X >= 0 && maze[Y][X] == '0' && visit[Y][X] != true)	
			{
				ptr = new Queue;			
				ptr->xpos = X;				
				ptr->ypos = Y;				
				ptr->check = l;				
				tail->next = ptr;			
				tail = ptr;					
				tail->next = NULL;			
				visit[Y][X] = true;			
			}
		}
		Queue* del = head;					
		head = head->next;					
		delete del;							
	}
	if (head == NULL) { cout << "No path"; return 0; }
	cout << l - 1;							
	ptr = head;								
	while (ptr != NULL)						
	{
		head = ptr;
		ptr = ptr->next;
		delete head;
	}
}
