// 4차 과제 1번: 기존 프로그램의 오류를 점검한 수정본
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char order[20];			
	int stack[128]={};		
	int i=0, cnt=0;			
	while (1)
	{
		cin >>order;			
		cin.ignore();
		if (strcmp(order, "push")==0)		
		{
			if (i >= 128) { cerr << "Stack is full" << endl; int ignored; cin >> ignored; continue; }
			cin >> stack[i];				
			i++;							
		}
		else if (strcmp(order, "pop")==0)	
		{
			if (i!= 0)						
			{
				cout << stack[i - 1] << endl;	
				stack[i - 1] = NULL;			
				i--;						
			}
		}
		else if (strcmp(order,"top")==0)	
		{
			if(i!=0)						
			cout << stack[i - 1] << endl;	
		}
		else if (strcmp(order, "print")==0)		
		{
			while (cnt!=i)					
			{
				cout << stack[cnt]<<" ";	
				cnt++;						
			}
			cout << endl;
			cnt = 0;						
		}
		else if (strcmp(order,"empty")==0)	
		{
			if (i == 0)						
				cout << "1"<<endl;			
			else							
				cout << "0"<<endl;			
		}
		else								
			break;							
	}
		
}
