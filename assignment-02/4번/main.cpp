// 2차 과제 4번: 기존 프로그램의 오류를 점검한 수정본
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

// 두 정수의 값을 직접 교환한다.
void swapValues(int& left, int& right) { int temp = left; left = right; right = temp; }

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
	int x[2], y[2], X, Y;		
	char a[100] = { 0 }, b[10] = { 0 }, name[100] = { 0 },first[10], second[10], store[3][100];
	FILE* fpInputImage = 0;
	FILE* fpOutputImage = 0;
	uint8_t** ppInputImageBuffer = 0;;
	uint8_t temp;
	char* IMG_NAME = name;
	cout << "Input file name: ";			
	cin >> IMG_NAME;
	cin.ignore();
	cout << "1st coordinate: ";				
	cin >> x[0];
	cin.ignore();
	cin >> y[0];
	cout << "2st coordinate: ";				
	cin >> x[1];
	cin.ignore();
	cin >> y[1];
	if (x[0] > x[1])
	{
		swapValues(x[0], x[1]);
	}
	if (y[0] > y[1])
	{
		swapValues(y[0], y[1]);
	}
	X = x[1] - x[0];						
	Y = y[1] - y[0];						
	_itoa(X, a, 10);						
	_itoa(Y, b, 10);						
	strcat(a, "x");							
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

	fpOutputImage = fopen(strcat(strcat(strtok(store[0], "."), "_cropped_"), a), "wb");			
	for (i = y[0]; i < y[1]; i++)
	{
		fwrite((uint8_t*)ppInputImageBuffer[i] + x[0], sizeof(uint8_t), X, fpOutputImage);		
	}

	fclose(fpOutputImage);
	fpOutputImage = fopen(strcat(strtok(store[1], "."), "_horizontalflip.raw"), "wb");
	for (i = 0; i < IMG_HEIGHT; i++)
	{
		for (j = 0; j < IMG_WIDTH / 2; j++)
		{
			temp = ppInputImageBuffer[i][j];
			ppInputImageBuffer[i][j] = ppInputImageBuffer[i][IMG_WIDTH - 1 - j];				
			ppInputImageBuffer[i][IMG_WIDTH - 1 - j] = temp;
		}
	}
	for (i = 0; i < IMG_HEIGHT; i++)
	{
		fwrite((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fpOutputImage);		
	}
	for (i = 0; i < IMG_HEIGHT; i++)
	{
		for (j = 0; j < IMG_WIDTH / 2; j++)
		{
			temp = ppInputImageBuffer[i][j];
			ppInputImageBuffer[i][j] = ppInputImageBuffer[i][IMG_WIDTH - 1 - j];				
			ppInputImageBuffer[i][IMG_WIDTH - 1 - j] = temp;
		}
	}

	fclose(fpOutputImage);
	fpOutputImage = fopen(strcat(strtok(store[2], "."), "_verticalflip.raw"), "wb");
	for (i = IMG_HEIGHT - 1; i >= 0; i--)														
	{
		fwrite((uint8_t*)ppInputImageBuffer[i], sizeof(uint8_t), IMG_WIDTH, fpOutputImage);		
	}

	memory_free2D(ppInputImageBuffer);
	fclose(fpInputImage);
	fclose(fpOutputImage);
	return 0;
}
