// 1차 과제 4번: 기존 프로그램의 오류를 점검한 수정본
#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    double matrix[3][3],C[3][3] = {0},Ct[3][3];         
    int i, j;
    double det=0;                                     
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];                        
        }
    }
    
    C[0][0] = matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2];            
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
            Ct[j][i] = C[i][j];         
        }
    }

    det = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] -
        (matrix[0][2] * matrix[1][1] * matrix[2][0] + matrix[0][1] * matrix[1][0] * matrix[2][2] + matrix[0][0] * matrix[1][2] * matrix[2][1]);
    


    if (det == 0)
        cout << "The inverse matrix does not exist.";           

    else                                                       
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                matrix[i][j] = Ct[i][j] / det;                  
                cout << matrix[i][j] << " ";                    
            }
            cout << endl;
        }
    }
}
