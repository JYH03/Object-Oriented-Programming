// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include "ooplinalg.h"
#include <iostream>
using namespace std;
using namespace ooplinalg;
void printMatrix(const Matrix &m) {
    for (int i = 0; i < m.getRows(); ++i) {
        for (int j = 0; j < m.getCols(); ++j)
            cout << m.getElement(i, j) << "\t";
        cout << endl;
    }
}
int main() {
    float data[3][3] = {{2, 2, 3}, {1, 1, 2}, {1, 2, 3}};
    Matrix mat(3, 3);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            mat.setElement(i, j, data[i][j]);
    cout << "mat : " << endl;
    printMatrix(mat);
    cout << "determinant of mat : " << mat.determinant() << endl;
    Matrix mat1(3, 3);
    elementAdd(mat1, mat, 3);
    cout << endl << "elementAdd 3" << endl;
    printMatrix(mat1);
    Matrix mat2(3, 3);
    elementSub(mat2, mat, 2);
    cout << endl << "elementSub 2" << endl;
    printMatrix(mat2);
    Matrix mat3(3, 3);
    elementMul(mat3, mat, 4);
    cout << endl << "elementMul 4" << endl;
    printMatrix(mat3);
    Matrix mat4(3, 3);
    elementDiv(mat4, mat, 3);
    cout << endl << "elementDiv 3" << endl;
    printMatrix(mat4);
    float data1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix mat5(3, 3);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            mat5.setElement(i, j, data1[i][j]);
    cout << endl << "mat5 : " << endl;
    printMatrix(mat5);
    Matrix mat6(3, 3);
    add(mat6, mat, mat5);
    cout << endl << "add func with mat, mat5" << endl;
    printMatrix(mat6);
    Matrix mat7(3, 3);
    sub(mat7, mat, mat5);
    cout << endl << "sub func with mat, mat5" << endl;
    printMatrix(mat7);
    Matrix mat8(3, 3);
    mul(mat8, mat, mat5);
    cout << endl << "mul func with mat, mat5" << endl;
    printMatrix(mat8);
    Matrix mat10(mat5), mat11(3, 3);
    transpose(mat11, mat10);
    cout << endl << "transpose of mat5" << endl;
    printMatrix(mat11);
    float data2[3][3] = {{1, 4, 1}, {2, 3, 1}, {0, 2, 1}};
    Matrix mat9(3, 3);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            mat9.setElement(i, j, data2[i][j]);
    cout << endl << "mat9 : " << endl;
    printMatrix(mat9);
    Matrix mat12(3, 3);
    adjoint(mat12, mat9);
    cout << "adjoint matrix of mat9 : " << endl;
    printMatrix(mat12);
    Matrix mat13(3, 3);
    inverse(mat13, mat9);
    cout << "inverse matrix of mat9 : " << endl;
    printMatrix(mat13);
}
