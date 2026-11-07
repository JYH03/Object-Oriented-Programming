// 01반_02반_2022202078_조영훈 1-1주차 4번.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    double matrix[3][3],C[3][3] = {0},Ct[3][3];         //matrix:행렬 A C:여인수 행렬 Ct:여인수 행렬의 전치행렬
    int i, j,det=0;                                     //det: 행렬식
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];                        //행렬 A를 입력받음
        }
    }
    
    C[0][0] = matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2];            //여인수행렬 저장
    C[0][1] = -(matrix[1][0] * matrix[2][2] - matrix[2][0] * matrix[1][2]);
    C[0][2] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
    C[1][0] = -(matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]);
    C[1][1] = matrix[0][0] * matrix[2][2] - matrix[2][0] * matrix[0][2];
    C[1][2] = -(matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0]);
    C[2][0] = matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2];
    C[2][1] = -(matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2]);
    C[2][2] = matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            Ct[j][i] = C[i][j];         //여인수행렬의 전치행렬 저장
        }
    }

    det = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] -
        (matrix[0][2] * matrix[1][1] * matrix[2][0] + matrix[0][1] * matrix[1][0] * matrix[2][2] + matrix[0][0] * matrix[1][2] * matrix[2][1]);
    //행렬식 저장


    if (det == 0)
        cout << "The inverse matrix does not exist.";           //행렬식이 0일 때 역행렬이 존재하지 않음

    else                                                       
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                matrix[i][j] = Ct[i][j] / det;                  //여인수행렬의 전치행렬을 행렬식으로 나눠 
                cout << matrix[i][j] << " ";                    //역행렬을 만들어 출력
            }
            cout << endl;
        }
    }
}


