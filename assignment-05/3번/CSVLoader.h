#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

class CSVLoader
{
public:
	static constexpr unsigned int MAX_BUFFER_SIZE = 128;

	CSVLoader();
	CSVLoader(const char* path);
	~CSVLoader();

	float** getData() const;
	int getRows() const;
	int getCols() const;

	void parse(const char* path);
	void print(void);

private:
	float** data;
	int cols;
	int rows;
};