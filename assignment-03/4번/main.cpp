// 01반_02반_2022202078_조영훈 1-3주차 4번.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
void bubblesort(int fighting[], int length)
{
	int tmp = 0;
	for (int i = 0; i < length; i++)				//배열 속 정수들을 모두 검사
	{
		for (int j = length - 1; j > 0; j--)			//맨 끝 정수부터 오른쪽으로 검사
		{
			if (fighting[j] < fighting[j - 1])		//오른쪽에 있는 수가 왼쪽에 있는 수보다 작으면
			{
				swap(fighting[j], fighting[j - 1]);	//교환
			}
		}
	}
	return;
}
void insertionsort(int fighting[], int length)
{
	int wall;			//검사할 기준
	int i, j;
	for (i = 1; i < length; i++)		//배열에 입력된 길이만큼 검사
	{								
		wall = fighting[i];				//검사할 기준(0~length-1 중 1번 째 부터)
		bool located = false;			//for문을 중단할 변수, 거짓으로 선언
		for (j = i - 1; j >= 0&&!located;)			//검사할 기준의 왼쪽들을 비교, 참이면 중단
		{
			if (fighting[j] > wall)					//왼쪽에 있는 수가 기준보다 크면
			{
				fighting[j + 1] = fighting[j];		//왼쪽에있는 수를 오른쪽 한칸으로 이동
				j--;
			}
			else
			{
				located = true;					//중단용 참
			}
		}
		fighting[j + 1] = wall;					//모두 이동 후 남은 빈 자리에 기준 값을 넣음(j가 -1이어서 j+1)
	}
}
int sort[1000] = { 0 };											//복사용 배열
void mergesort(int fighting[], int start, int mid, int end)
{
	int i = start, j = mid + 1, k = start,x;		//i에 시작점 j에 중간점+1 값을 넣음, k는 복사용배열에 쓰일 변수 

	//정렬하여 입력하는 코드
	while (i <= mid && j <= end)					//왼쪽 배열은 mid보다 작거나 같을 때까지 오른쪽 배열은 mid+1~end까지
	{
		if (fighting[i] <= fighting[j])				//왼쪽 배열 값이 오른쪽 배열 값보다 작으면 
			sort[k++] = fighting[i++];				//복사용 배열에 왼쪽 배열을 넣음
		else										//왼쪽 배열 값이 오른쪽 배열 값보다 크면 
			sort[k++] = fighting[j++];				//복사용 배열에 오른쪽 배열을 넣음
	}


	if (i > mid)									//i가 배열 중앙을 넘어가면
	{
		for (x = j; x <= end; x++)					//j부터 
			sort[k++] = fighting[x];				//end 까지 나머지 전부 복사
	}
	else 
	{
		for (x = i; x <= mid; x++)					//i부터 
			sort[k++] = fighting[x];				//mid 까지 나머지 전부 복사
	}

	for (x = start; x <= end; x++)					//복사했던 값들을
	{	
		fighting[x] = sort[x];						//기존 배열로 재복사
	}

}
void realmerge(int fighting[], int start, int end) 
{
	int mid;					//배열을 나눌 중앙을 저장할 변수 선언

	if (start < end) 
	{
		mid = (start + end) / 2;				//중앙 저장
		realmerge(fighting, start, mid);		//재귀로 최소 단위까지 분할
		realmerge(fighting, mid + 1, end);		//재귀로 최소 단위까지 분할
		mergesort(fighting, start, mid, end);	//두 부분을 다시 합침
	}
}
void quicksort(int fighting[], int start, int end)
{
	if (start >= end) return;
	int i = start, j = end;
	int pivot = fighting[(start + end) / 2];		//pivot은 중앙위치의 값 이때 (start+end)/2로만 저장하면 중앙 pivot이 바뀌는 문제가 생김!
	while (i <= j)
	{
		while (fighting[i] < pivot) i++;		//맨 왼쪽 부터 pivot까지 검사해서 pivot위치의 값보다 클 때까지 i++
		while (fighting[j] > pivot) j--;		//맨 오른쪽 부터 pivot까지 검사해서 pivot위치의 값보다 작을 때까지 j--
		if (i <= j)
		{
			swap(fighting[i], fighting[j]);				//pivot을 기준으로 왼쪽에 더 큰 수와 오른쪽에 더 작은 수를 서로 교환
				i++;
				j--;
		}
	}
	quicksort(fighting, start, j);					//다시 처음~j지점 까지 quicksort 방식으로 정렬
	quicksort(fighting, i, end);					//다시 i~끝지점 까지 quicksort 방식으로 정렬
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
	//bubblesort(fighting, N);						//bubblesort
	//insertionsort(fighting, N);					//insertionsort
	//realmerge(fighting, 0, N - 1);				//mergesort
	quicksort(fighting, 0, N-1);					//quicksort
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

