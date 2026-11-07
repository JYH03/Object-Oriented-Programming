#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

char* Sender(const char* input_data,char* P) 
{
    int divisor=0;
    int data1=0;
    int data2;
    char coded_frame[17];
    for (int i = 0; i < 5; i++)
    {
        divisor += pow(2, 4 - i) * (P[i] - '0');        //2진수 문자형을 10진수 int형으로 변환
    }

    for (int i = 0; i < 12; i++) 
    {
        data1 += pow(2, 11 - i) * (input_data[i] - '0');    //2진수 문자형을 10진수 int 형으로 변환
    }

    data1 = data1 << 4;               //12bit -> 16bit
    data2 = data1;
    divisor = divisor << 11;          //5bit -> 16bit

    while (1) 
    {
        data2 = data2 ^ divisor;       //data를 divisor와 xor 연산

        while (1) 
        {
            divisor = divisor >> 1;     //나눠서 작아진 data와의 칸 수를 맞추기 위해 칸을 밀어서
            if (divisor > data2 && divisor / data2 < 2)     // divisor가 data보다 크고 data의 2배보다 divisor가 작거나 
                break;
            else if (divisor < data2)                       //divisor가 data보다 작아질 때까지 칸을 밀고 xor 연산
                break;
        }
        if (data2 <= 15)                                    //마지막 4bit 속 최대 값인 15보다 작거나 같으면
            break;                                          //연산종료
    }

    data1 = data1 + data2;                                  // 4bit 4자리 값을 원래 data값에 추가해서

    for (int i = 15; i >= 0; i--) 
    {
        coded_frame[i] = data1 % 2 + '0';                   //10진수 int형으로 계산한 것을 2진수 문자형으로 변환
        data1 /= 2;
    }

    coded_frame[16] = '\0';                            //마지막 배열에 \0 넣기

    cout << "Coded frame : ";                           
    cout << coded_frame << endl;

    return coded_frame;                                //계산한 문자열 반환
}

char* Transmission_Channel(const char* coded_frame)         //Input const char* coded_frame
{
    char data[17];
    int N;

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 16; i++) 
    {
        N = rand() % 20;                        //  5/100 = 1/20 -> 0~19

        if (!N)                                 //  0일 때
        {
            if (coded_frame[i] == '0')          //  맨 뒷자리부터 0이면
                data[i] = '1';                  //  1 저장
            else data[i] = '0';                 //  1이면 0 저장
        }
        else data[i] = coded_frame[i];          //오류발생하지 않았음으로 그대로 저장
    }

    data[16] = '\0';                            //마지막에 \0저장

    return data;                                //반환
}
void Receiver(const char* received_frame,char * P) 
{
    int k=0;
    int data1 = 0;
    int data2;
    int divisor=0;
    char reconstructed_data[13];
    char coded_frame[17];
    for (int i = 0; i < 5; i++)
    {
        divisor += pow(2, 4 - i) * (P[i] - '0');        //2진수 문자형을 10진수 int형으로 변환
    }

    for (int i = 0; i < 16; i++) 
    {
        coded_frame[i] = received_frame[i];            //xor배열에 에러를 추가한 배열을 저장(출력용)
    }

    coded_frame[16] = '\0';                            //마지막에 \0 저장

    cout << "Received frame : ";
    cout << coded_frame << endl;                        //송신 받은 데이터 출력

    for (int i = 0; i < 16; i++) 
    {
        data1 += pow(2, 15 - i) * (coded_frame[i] - '0');   //2진수 문자형을 10진수 int형으로 변환
    }

    data2 = data1;                                  
    divisor = divisor << 11;                           //5bit -> 16bit
    while (divisor >=32) 
    {
        data2 = data2 ^ divisor; 
                           //data를 divisor와 xor 연산
        while (1) 
        {
            divisor = divisor >> 1;                     //나눠서 작아진 data와의 칸 수를 맞추기 위해 칸을 밀어서
            k++;

            if (divisor > data2 && divisor / data2 < 2)     // divisor가 data보다 크고 data의 2배보다 divisor가 작거나
                break;
            else if (divisor < data2)                   //divisor가 data보다 작아질 때까지 칸을 밀고 xor 연산
                break;
            else
                break;
        }
        if (data2 <= 15)                                //마지막 4bit 속 최대 값인 15보다 작거나 같으면
        {
            break;                                      //연산종료
        }
    }
    data1 = data1 >> 4;                                 //fcs 제외한 (16->12 bit)

    for (int i = 11; i >= 0; i--) 
    {                     
        reconstructed_data[i] = data1 % 2 + '0';       //2진수 문자형으로 변환
        data1 /= 2;
    }

    reconstructed_data[12] = '\0';                      //마지막에 \0 저장

    cout << "Reconstructed data : ";
    cout << reconstructed_data << endl;                 //reconstructed data 출력

    if (data2 == divisor)                               //임의로 지정한 P와 xor연산 나머지가 같으면
    {                                                   
        cout << "No detected error" << endl;            //에러가 존재하지 않음
    }
    else 
        cout << "Receiver has detected error" << endl; //그렇지 않으면 에러가 존재함
}


int main()
{
	int i;
    char* Code;
    char Temporary1[17];
    char Temporary2[17];
	char T[16], D[50], P[5]={'1','1','0','1','1'};
	cout << "Data: ";								//data 입력 받음
	cin >> D;
	strcpy(T, D);									//data 뒤
	for (i = 12; i < 16; i++)						
	{
		T[i] = '0';									//남은 4자리를 0으로 채워줌
	}
	
    Code = Sender(T,P);                             //xor 연산 해서 만든 새 문자열 저장

    for (i = 0; i < 16; i++)
    {
        Temporary1[i] = Code[i];                     //Temporary 배열에 복사
    }
    Temporary1[16] = '\0';

    Code = Transmission_Channel(Temporary1);         //기존 xor한 배열에 에러를 만듬

    for (i = 0; i < 16; i++)
    {
        Temporary2[i] = Code[i];                     //Temporary 배열에 복사
    }
    Temporary2[16] = '\0';

    Receiver(Temporary2,P);
}