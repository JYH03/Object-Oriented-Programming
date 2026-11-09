// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include <iostream>

using namespace std;

class Matrix {
  private:
    double elements[3][3];

  public:
    Matrix(double value = 0.0);
    void print();
    Matrix &operator+=(const Matrix &other);
    Matrix &operator-=(const Matrix &other);
    Matrix operator*(const Matrix &other);
};

Matrix::Matrix(double value) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {

            elements[i][j] = value;
        }
    }
}

void Matrix::print() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << elements[i][j] << ' ';
        }
        cout << endl;
    }
}

Matrix &Matrix::operator+=(const Matrix &other) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            elements[i][j] += other.elements[i][j];
        }
    }

    return *this;
}

Matrix &Matrix::operator-=(const Matrix &other) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            elements[i][j] -= other.elements[i][j];
        }
    };

    return *this;
}

Matrix Matrix::operator*(const Matrix &other) {
    Matrix result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {

            result.elements[i][j] = 0;
            for (int k = 0; k < 3; ++k)
                result.elements[i][j] += this->elements[i][k] * other.elements[k][j];
        }
    }
    return result;
}

int main() {
    Matrix m1(1.0), m2(2.0);

    cout << "Matrix m1:" << endl;
    m1.print();

    cout << "Matrix m2:" << endl;
    m2.print();

    m1 += m2;
    cout << "Matrix 1 += Matrix 2:" << endl;
    m1.print();

    m1 -= m2;
    cout << "Matrix 1 -= Matrix 2:" << endl;
    m1.print();

    Matrix m3 = m1 * m2;
    cout << "Matrix 1 * Matrix 2:" << endl;
    m3.print();

    return 0;
}
