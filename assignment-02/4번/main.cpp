// 01반_02반_2022202078_조영훈 1-2주차 4번.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#define IMG_HEIGHT 512
#define IMG_WIDTH 512
uint8_t** memory_alloc2D(uint32_t height, uint32_t width)
{
	uint8_t** ppMem2d = new uint8_t * [height];
	if (ppMem2d == 0)
		return 0;
	ppMem2d[0] = new uint8_t[height * width];
	if (ppMem2d[0] == 0)
	{
		delete[] ppMem2d;
		return 0;
	}
	for (int i = 1; i < height; i++)
		ppMem2d[i] = ppMem2d[i - 1] + width;
	return ppMem2d;
}
int memory_free2D(uint8_t** ppMemAllocated)
{
	if (ppMemAllocated == 0)
		return -1;
	if (ppMemAllocated[0])
		delete[] ppMemAllocated[0];
	delete[] ppMemAllocated;
	return 0;
}

int main()
{
	int i, len, j = 0;
	int x[2], y[2], X, Y;		//x는 자를 크기의 x값을 저장할 배열이고 y는 자를 크기의 y값을 저장할 배열
	char a[100] = { 0 }, b[10] = { 0 }, name[100] = { 0 },first[10], second[10], store[3][100];
	FILE* fpInputImage = 0;
	FILE* fpOutputImage = 0;
	uint8_t** ppInputImageBuffer = 0;;
	uint8_t temp;
	char* IMG_NAME = name;
	cout << "Input file name: ";			//파일의 이름 입력
	cin >> IMG_NAME;
	cin.ignore();
	cout << "1st coordinate: ";				//자를 크기의 왼쪽 위 좌표 입력(배열 기준)
	cin >> x[0];
	cin.ignore();
	cin >> y[0];
	cout << "2st coordinate: ";				//자를 크기의 오른쪽 아래 좌표 입력(배열 기준)
	cin >> x[1];
	cin.ignore();
	cin >> y[1];
	if (x[0] > x[1])
	{
		swap(x[0], x[1]);
	}
	if (y[0] > y[1])
	{
		swap(y[0], y[1]);
	}
	X = x[1] - x[0];						//두 좌표의 x값의 차
	Y = y[1] - y[0];						//두 좌표의 y값의 차
	_itoa(X, a, 10);						//사진의 크기 출력을 위해 정수 x값의 차를 문자열로 변환
	_itoa(Y, b, 10);						//사진의 크기 출력을 위해 정수 x값의 차를 문자열로 변환
	strcat(a, "x");							//axb.raw 문구 만들기
	strcat(a, b);
	strcat(a, ".raw");
	for (i = 0; i < 3; i++)
	{
		strcpy(store[i] , IMG_NAME);
	}

	fpInputImage = fopen(IMG_NAME, "rb");
	ppInputImageBuffer = memory_alloc2D(IMG_HEIGHT, IMG_WIDTH);
	for (i = 0; i < IMG_HEIGHT; i++)
		fread((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fpInputImage);

	fpOutputImage = fopen(strcat(strcat(strtok(store[0], "."), "_cropped_"), a), "wb");			//지정한 이름으로 파일을 열어(없으면 생성)
	for (i = y[0]; i < y[1]; i++)
	{
		fwrite((uint8_t*)ppInputImageBuffer[i] + x[0], sizeof(uint8_t), X, fpOutputImage);		// x[0], y[0] 부터 X길이 만큼 y[0]~y[1]길이 만큼 출력
	}

	fpOutputImage = fopen(strcat(strtok(store[1], "."), "_horizontalflip.raw"), "wb");
	for (i = 0; i < IMG_HEIGHT; i++)
	{
		for (j = 0; j < IMG_WIDTH / 2; j++)
		{
			temp = ppInputImageBuffer[i][j];
			ppInputImageBuffer[i][j] = ppInputImageBuffer[i][IMG_WIDTH - 1 - j];				//좌우 반전을 위한 포인터의 위치를 교환
			ppInputImageBuffer[i][IMG_WIDTH - 1 - j] = temp;
		}
	}
	for (i = 0; i < IMG_HEIGHT; i++)
	{
		fwrite((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fpOutputImage);		//좌우반전된 값 출력
	}
	for (i = 0; i < IMG_HEIGHT; i++)
	{
		for (j = 0; j < IMG_WIDTH / 2; j++)
		{
			temp = ppInputImageBuffer[i][j];
			ppInputImageBuffer[i][j] = ppInputImageBuffer[i][IMG_WIDTH - 1 - j];				//좌우 반전을 원 상태로 돌리기 위해 다시 교환
			ppInputImageBuffer[i][IMG_WIDTH - 1 - j] = temp;
		}
	}

	fpOutputImage = fopen(strcat(strtok(store[2], "."), "_verticalflip.raw"), "wb");
	for (i = IMG_HEIGHT - 1; i >= 0; i--)														//y값이 상하반전을 위해 최대값 511 부터 0까지
	{
		fwrite((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fpOutputImage);		//상하반전된 값 출력
	}

	memory_free2D(ppInputImageBuffer);
	fclose(fpInputImage);
	fclose(fpOutputImage);
	return 0;
}

//fwrite((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fpOutputImage);

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
