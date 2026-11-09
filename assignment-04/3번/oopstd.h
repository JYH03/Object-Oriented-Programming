// 문자열 및 메모리 함수의 경계와 반환값을 수정한 버전
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
		unsigned char* str;				
		str = (unsigned char*)ptr;		
		for (int i = 0; i < num; i++)	
		{
			str[i] = value;				
		}
		return (void*)str;				
	}
	void* memcpy(void* destination, const void* source, size_t num)
	{
		int i;
		unsigned char* str1 = (unsigned char*)destination;	
		unsigned char* str2 = (unsigned char*)source;
		for (i = 0; i < num; i++)
		{
			str1[i] = str2[i];				
		}
		return (void*)str1;					
	}
	int strcmp(const char* str1, const char* str2)
	{
		while (*str1 && *str2)			
		{
			if (*str1 != *str2)			
			{
				return (static_cast<unsigned char>(*str1) < static_cast<unsigned char>(*str2)) ? -1 : 1;		
			}
			str1++, str2++;								
		}
		if (*str1 != *str2)								
			return (static_cast<unsigned char>(*str1) < static_cast<unsigned char>(*str2)) ? -1 : 1;
		return 0;										
	}
	int strncmp(const char* str1, const char* str2, size_t num)
	{
		for (size_t i = 0; i < num; ++i) {
			unsigned char a = static_cast<unsigned char>(str1[i]);
			unsigned char b = static_cast<unsigned char>(str2[i]);
			if (a != b) return a < b ? -1 : 1;
			if (a == 0) return 0;
		}
		return 0;
	}

	char* strcpy(char* destination, const char* source)
	{
		char* begin = destination;
		while ((*destination++ = *source++) != '\0') {}
		return begin;
	}
	char* strncpy(char* destination, const char* source, size_t num)
	{
		size_t i = 0;
		for (; i < num && source[i] != '\0'; ++i) destination[i] = source[i];
		for (; i < num; ++i) destination[i] = '\0';
		return destination;
	}

	size_t strlen(const char* str)
	{
		int num = 0;
		while (*str)						
		{
			num++;							
			*str++;							
		}
		return num;							
	}
	int atoi(const char* str) {
        while ((*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' || *str == '\f')) ++str;
        int sign = 1;
        if (*str == '-' || *str == '+') { if (*str == '-') sign = -1; ++str; }
        int value = 0;
        while (*str >= '0' && *str <= '9') value = value * 10 + (*str++ - '0');
        return sign * value;
    }
    double atof(const char* str) {
        while ((*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' || *str == '\f')) ++str;
        int sign = 1;
        if (*str == '-' || *str == '+') { if (*str == '-') sign = -1; ++str; }
        double value = 0;
        while (*str >= '0' && *str <= '9') value = value * 10 + (*str++ - '0');
        if (*str == '.') {
            ++str; double place = 0.1;
            while (*str >= '0' && *str <= '9') { value += (*str++ - '0') * place; place *= 0.1; }
        }
        if (*str == 'e' || *str == 'E') {
            const char* exp = str + 1; int esign = 1;
            if (*exp == '-' || *exp == '+') { if (*exp == '-') esign = -1; ++exp; }
            int power = 0;
            while (*exp >= '0' && *exp <= '9') { power = power * 10 + (*exp++ - '0'); if (power > 10000) { power = 10000; break; } }
            value *= std::pow(10.0, esign * power);
        }
        return sign * value;
    }
}
