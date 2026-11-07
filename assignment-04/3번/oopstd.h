#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
using namespace std;

namespace oopstd
{
	void* memset(void* ptr, int value, size_t num)
	{
		unsigned char* str;				//char형 포인터 선언
		str = (unsigned char*)ptr;		//void로 입력받아 char형으로 인식
		for (int i = 0; i < num; i++)	//크기 만큼
		{
			str[i] = value;				//값 입력
		}
		return (void*)str;				//반환
	}
	void* memcpy(void* destination, const void* source, size_t num)
	{
		int i;
		unsigned char* str1 = (unsigned char*)destination;	//void로 입력받아 char형으로 인식 후 포인터 지정
		unsigned char* str2 = (unsigned char*)source;
		for (i = 0; i < num; i++)
		{
			str1[i] = str2[i];				//값 복사
		}
		return (void*)str1;					//반환
	}
	int strcmp(const char* str1, const char* str2)
	{
		while (*str1 && *str2)			//같은 동안 검사 진행
		{
			if (*str1 != *str2)			//다르면
			{
				return (*str1 < *str2) ? -1 : 1;		//처음 값이 더 작으면 -1 그렇지 않으면 1 반환
			}
			str1++, str2++;								//다음 글자로 진행
		}
		if (*str1 != *str2)								//글자수 차이 고려
			return(*str1 < *str2) ? -1 : 1;
		return 0;										//반환
	}
	int strncmp(const char* str1, const char* str2, size_t num)
	{
		for (int i = 0; i < num; i++)					//크기만큼
		{
			if (*str1 != *str2)							//검사
			{
				return (*str1 < *str2) ? -1 : 1;		//처음 값이 더 작으면 -1 그렇지 않으면 1 반환
			}
			str1++, str2++;								//진행
		}
		return 0;
	}
	char* strcpy(char* destination, const char* source)
	{
		while (*source)								//복사하고자 하는 문자열 만큼
		{
			*destination++ = *source++;				//복사
		}
		*destination = '\0';						//문자열의 끝을 알리는 '\0'
		return destination;							//반환
	}
	char* strncpy(char* destination, const char* source, size_t num)
	{
		int i;
		for (i = 0; i < num; i++)				//입력받은 크기만큼
		{
			destination[i] = source[i];			//복사
		}
		return destination;						//반환
	}
	size_t strlen(const char* str)
	{
		int num = 0;
		while (*str)						//문자열 만큼
		{
			num++;							//카운트
			*str++;							//문자열 진행
		}
		return num;							//반환
	}
	int	atoi(const char* str)
	{
		int i = 0;
		int num = 0;
		int cnt = -1;
		while (str[i++] != '\0')		//문자열의 길이
		{
			cnt++;						//카운트-1
		}
		while (*str)
		{
			num += (*str - '0') * pow(10, cnt--);				//각 자리수는 10^(카운트 -1) * 자리의 값, 카운트-1은 위에서 해결함
			*str++;												//진행
		}
		return num;												//반환
	}
	float atof(const char* str)
	{
		int i = 0;
		int cnt = 0;
		float num = 0;
		while (str[i] != '.' && str[i] != '\0')				//문자열의 끝이거나 .을 만날 때 까지
		{
			cnt++;											//카운트
			i++;
		}
		while (*str != '.' && *str != '\0')					//문자열의 끝이거나 .을 만날 때 까지
		{
			num += (*str - '0') * pow(10, --cnt);			//각 자리수는 10^(카운트 -1) * 자리의 값
			*str++;											//진행
		}
		if (*str == '.')									//.을 만나면
		{
			*str++;											//.다음 자리로 진행
			while (*str != '\0')							//문자열의 끝까지
			{
				num += (*str - '0') * pow(10, --cnt);		//각 자리수는 10^(카운트 -1) * 자리의 값
				*str++;										//진행
			}
		}
		return num;											//반환
	}

}