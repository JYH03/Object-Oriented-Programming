// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include "ooplinalg.h"
#include <cmath>
#include <stdexcept>
namespace ooplinalg {
Matrix::Matrix() : data(nullptr), rows(0), cols(0) {}
Matrix::Matrix(int r, int c) : data(nullptr), rows(r), cols(c) {
    if (r < 0 || c < 0)
        throw std::invalid_argument("negative matrix size");
    if (!r)
        return;
    data = new float *[r] {};
    try {
        for (int i = 0; i < r; ++i)
            data[i] = new float[c]{};
    } catch (...) {
        for (int i = 0; i < r; ++i)
            delete[] data[i];
        delete[] data;
        throw;
    }
}
Matrix::Matrix(const Matrix &m) : Matrix(m.rows, m.cols) { setData(rows, cols, m.data); }
Matrix &Matrix::operator=(const Matrix &m) {
    if (this != &m) {
        Matrix copy(m);
        float **d = data;
        data = copy.data;
        copy.data = d;
        int r = rows;
        rows = copy.rows;
        copy.rows = r;
        int c = cols;
        cols = copy.cols;
        copy.cols = c;
    }
    return *this;
}
Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i)
        delete[] data[i];
    delete[] data;
}
float Matrix::getElement(int r, int c) const {
    if (r < 0 || c < 0 || r >= rows || c >= cols)
        throw std::out_of_range("matrix index");
    return data[r][c];
}
float **Matrix::getData() const { return data; }
void Matrix::setElement(int r, int c, float value) {
    if (r < 0 || c < 0 || r >= rows || c >= cols)
        throw std::out_of_range("matrix index");
    data[r][c] = value;
}
void Matrix::setData(int r, int c, float **src) {
    if (r != rows || c != cols)
        throw std::invalid_argument("matrix size");
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            data[i][j] = src[i][j];
}
void Matrix::setRows(int r) {
    if (r != rows)
        throw std::invalid_argument("cannot resize using setRows");
}
int Matrix::getRows() const { return rows; }
void Matrix::setCols(int c) {
    if (c != cols)
        throw std::invalid_argument("cannot resize using setCols");
}
int Matrix::getCols() const { return cols; }

float Matrix::determinant() const {
    if (rows != cols || rows == 0)
        throw std::invalid_argument("determinant requires square matrix");
    Matrix temp(*this);
    double det = 1;
    for (int i = 0; i < rows; ++i) {
        int pivot = i;
        for (int r = i + 1; r < rows; ++r)
            if (std::fabs(temp.data[r][i]) > std::fabs(temp.data[pivot][i]))
                pivot = r;
        if (temp.data[pivot][i] == 0.0f)
            return 0.0f;
        if (pivot != i) {
            float *p = temp.data[pivot];
            temp.data[pivot] = temp.data[i];
            temp.data[i] = p;
            det = -det;
        }
        double v = temp.data[i][i];
        det *= v;
        for (int r = i + 1; r < rows; ++r) {
            double factor = temp.data[r][i] / v;
            for (int c = i + 1; c < cols; ++c)
                temp.data[r][c] -= static_cast<float>(factor * temp.data[i][c]);
        }
    }
    return static_cast<float>(det);
}
static void requireSize(const Matrix &m, int r, int c) {
    if (m.getRows() != r || m.getCols() != c)
        throw std::invalid_argument("matrix size mismatch");
}
Matrix &add(Matrix &r, const Matrix &a, const Matrix &b) {
    requireSize(b, a.getRows(), a.getCols());
    requireSize(r, a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i)
        for (int j = 0; j < a.getCols(); ++j)
            r.setElement(i, j, a.getElement(i, j) + b.getElement(i, j));
    return r;
}
Matrix &sub(Matrix &r, const Matrix &a, const Matrix &b) {
    requireSize(b, a.getRows(), a.getCols());
    requireSize(r, a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i)
        for (int j = 0; j < a.getCols(); ++j)
            r.setElement(i, j, a.getElement(i, j) - b.getElement(i, j));
    return r;
}
Matrix &mul(Matrix &r, const Matrix &a, const Matrix &b) {
    if (a.getCols() != b.getRows())
        throw std::invalid_argument("matrix multiplication dimensions");
    requireSize(r, a.getRows(), b.getCols());
    Matrix result(a.getRows(), b.getCols());
    for (int i = 0; i < a.getRows(); ++i)
        for (int j = 0; j < b.getCols(); ++j) {
            float v = 0;
            for (int k = 0; k < a.getCols(); ++k)
                v += a.getElement(i, k) * b.getElement(k, j);
            result.setElement(i, j, v);
        }
    r = result;
    return r;
}
Matrix &elementAdd(Matrix &r, const Matrix &a, float v) {
    requireSize(r, a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i)
        for (int j = 0; j < a.getCols(); ++j)
            r.setElement(i, j, a.getElement(i, j) + v);
    return r;
}
Matrix &elementSub(Matrix &r, const Matrix &a, float v) { return elementAdd(r, a, -v); }
Matrix &elementMul(Matrix &r, const Matrix &a, float v) {
    requireSize(r, a.getRows(), a.getCols());
    for (int i = 0; i < a.getRows(); ++i)
        for (int j = 0; j < a.getCols(); ++j)
            r.setElement(i, j, a.getElement(i, j) * v);
    return r;
}
Matrix &elementDiv(Matrix &r, const Matrix &a, float v) {
    if (v == 0)
        throw std::domain_error("division by zero");
    return elementMul(r, a, 1.0f / v);
}
Matrix &transpose(Matrix &r, const Matrix &m) {
    requireSize(r, m.getCols(), m.getRows());
    Matrix t(m.getCols(), m.getRows());
    for (int i = 0; i < m.getRows(); ++i)
        for (int j = 0; j < m.getCols(); ++j)
            t.setElement(j, i, m.getElement(i, j));
    r = t;
    return r;
}
Matrix &adjoint(Matrix &r, const Matrix &m) {
    int n = m.getRows();
    if (n != m.getCols() || n == 0)
        throw std::invalid_argument("adjoint requires square matrix");
    requireSize(r, n, n);
    Matrix result(n, n);
    if (n == 1) {
        result.setElement(0, 0, 1);
        r = result;
        return r;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            Matrix minor(n - 1, n - 1);
            int rr = 0;
            for (int x = 0; x < n; ++x) {
                if (x == i)
                    continue;
                int cc = 0;
                for (int y = 0; y < n; ++y) {
                    if (y == j)
                        continue;
                    minor.setElement(rr, cc++, m.getElement(x, y));
                }
                ++rr;
            }
            result.setElement(j, i, ((i + j) % 2 ? -1.0f : 1.0f) * minor.determinant());
        }
    r = result;
    return r;
}

Matrix &inverse(Matrix &r, const Matrix &m) {
    int n = m.getRows();
    if (n == 0 || n != m.getCols())
        throw std::invalid_argument("inverse requires square matrix");
    requireSize(r, n, n);
    Matrix work(m), result(n, n);
    for (int i = 0; i < n; ++i)
        result.setElement(i, i, 1);
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i + 1; j < n; ++j)
            if (std::fabs(work.getElement(j, i)) > std::fabs(work.getElement(pivot, i)))
                pivot = j;
        float divisor = work.getElement(pivot, i);
        if (divisor == 0)
            throw std::domain_error("inverse matrix does not exist");
        if (pivot != i)
            for (int c = 0; c < n; ++c) {
                float t = work.getElement(i, c);
                work.setElement(i, c, work.getElement(pivot, c));
                work.setElement(pivot, c, t);
                t = result.getElement(i, c);
                result.setElement(i, c, result.getElement(pivot, c));
                result.setElement(pivot, c, t);
            }
        for (int c = 0; c < n; ++c) {
            work.setElement(i, c, work.getElement(i, c) / divisor);
            result.setElement(i, c, result.getElement(i, c) / divisor);
        }
        for (int j = 0; j < n; ++j)
            if (j != i) {
                float factor = work.getElement(j, i);
                for (int c = 0; c < n; ++c) {
                    work.setElement(j, c, work.getElement(j, c) - factor * work.getElement(i, c));
                    result.setElement(j, c,
                                      result.getElement(j, c) - factor * result.getElement(i, c));
                }
            }
    }
    r = result;
    return r;
}
} // namespace ooplinalg
