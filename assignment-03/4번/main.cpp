// 3차 과제 4번: 기존 프로그램의 오류를 점검한 수정본
#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

// 두 정수의 값을 직접 교환한다.
void swapValues(int& left, int& right) { int temp = left; left = right; right = temp; }
void bubblesort(int fighting[], int length)
{
	int tmp = 0;
	for (int i = 0; i < length; i++)				
	{
		for (int j = length - 1; j > 0; j--)			
		{
			if (fighting[j] < fighting[j - 1])		
			{
				swapValues(fighting[j], fighting[j - 1]);	
			}
		}
	}
	return;
}
void insertionsort(int fighting[], int length)
{
	int wall;			
	int i, j;
	for (i = 1; i < length; i++)		
	{								
		wall = fighting[i];				
		bool located = false;			
		for (j = i - 1; j >= 0&&!located;)			
		{
			if (fighting[j] > wall)					
			{
				fighting[j + 1] = fighting[j];		
				j--;
			}
			else
			{
				located = true;					
			}
		}
		fighting[j + 1] = wall;					
	}
}
int sort[1000] = { 0 };											
void mergesort(int fighting[], int start, int mid, int end)
{
	int i = start, j = mid + 1, k = start,x;		

	
	while (i <= mid && j <= end)					
	{
		if (fighting[i] <= fighting[j])				
			sort[k++] = fighting[i++];				
		else										
			sort[k++] = fighting[j++];				
	}


	if (i > mid)									
	{
		for (x = j; x <= end; x++)					
			sort[k++] = fighting[x];				
	}
	else 
	{
		for (x = i; x <= mid; x++)					
			sort[k++] = fighting[x];				
	}

	for (x = start; x <= end; x++)					
	{	
		fighting[x] = sort[x];						
	}

}
void realmerge(int fighting[], int start, int end) 
{
	int mid;					

	if (start < end) 
	{
		mid = (start + end) / 2;				
		realmerge(fighting, start, mid);		
		realmerge(fighting, mid + 1, end);		
		mergesort(fighting, start, mid, end);	
	}
}
void quicksort(int fighting[], int start, int end)
{
	if (start >= end) return;
	int i = start, j = end;
	int pivot = fighting[(start + end) / 2];		
	while (i <= j)
	{
		while (fighting[i] < pivot) i++;		
		while (fighting[j] > pivot) j--;		
		if (i <= j)
		{
			swapValues(fighting[i], fighting[j]);				
				i++;
				j--;
		}
	}
	quicksort(fighting, start, j);					
	quicksort(fighting, i, end);					
}

int main()
{
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	int N, i, j;
	int fighting[1001] = { 0 };
	cout << "Input: ";
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> fighting[i];
		cin.ignore();
	}				
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	
	
	
	quicksort(fighting, 0, N-1);					
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	cout << "time: " << (double)diff.QuadPart / (double)ticksPerSec.QuadPart * pow(10, 6)<<"μsec" << endl;
	cout << "Sorted order: ";
	for (i = 0; i < N; i++)
	{
		cout << fighting[i]<<" ";
	}
	cout << endl<<"Median number: "<<fighting[N/2];
}
