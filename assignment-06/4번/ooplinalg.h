// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#pragma once
namespace ooplinalg {
class Matrix {
    float **data;
    int rows;
    int cols;

  public:
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const Matrix &other);
    Matrix &operator=(const Matrix &other);
    ~Matrix();
    float getElement(int row, int col) const;
    float **getData() const;
    void setElement(int row, int col, float value);
    void setData(int rows, int cols, float **source);
    void setRows(int rows);
    int getRows() const;
    void setCols(int cols);
    int getCols() const;
    float determinant() const;
};
Matrix &add(Matrix &r, const Matrix &a, const Matrix &b);
Matrix &sub(Matrix &r, const Matrix &a, const Matrix &b);
Matrix &mul(Matrix &r, const Matrix &a, const Matrix &b);
Matrix &elementAdd(Matrix &r, const Matrix &a, float v);
Matrix &elementSub(Matrix &r, const Matrix &a, float v);
Matrix &elementMul(Matrix &r, const Matrix &a, float v);
Matrix &elementDiv(Matrix &r, const Matrix &a, float v);
Matrix &transpose(Matrix &r, const Matrix &m);
Matrix &adjoint(Matrix &r, const Matrix &m);
Matrix &inverse(Matrix &r, const Matrix &m);
} // namespace ooplinalg
