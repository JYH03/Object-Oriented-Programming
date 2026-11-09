// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include "PolyTerm.h"
#include <climits>
#include <iostream>
using namespace std;
void spaces(const char *&p) {
    while (*p == ' ' || *p == '\t')
        ++p;
}

bool InputPolynomial(Polynomial &poly) {
    char line[4096];
    if (!cin.getline(line, sizeof(line)))
        return false;
    const char *p = line;
    bool first = true;
    spaces(p);
    while (*p) {
        int sign = 1;
        if (*p == '+' || *p == '-') {
            if (*p == '-')
                sign = -1;
            ++p;
        } else if (!first)
            return false;
        spaces(p);
        long long coefficient = 0;
        bool digits = false;
        while (*p >= '0' && *p <= '9') {
            digits = true;
            coefficient = coefficient * 10 + (*p++ - '0');
            if (coefficient > INT_MAX)
                return false;
        }
        spaces(p);
        int exponent = 0;
        if (*p == 'x') {
            ++p;
            if (!digits)
                coefficient = 1;
            exponent = 1;
            spaces(p);
            if (*p == '^') {
                ++p;
                spaces(p);
                int esign = 1;
                if (*p == '-' || *p == '+') {
                    if (*p == '-')
                        esign = -1;
                    ++p;
                }
                if (*p < '0' || *p > '9')
                    return false;
                long long e = 0;
                while (*p >= '0' && *p <= '9') {
                    e = e * 10 + (*p++ - '0');
                    if (e > INT_MAX)
                        return false;
                }
                exponent = static_cast<int>(e) * esign;
            }
        } else if (!digits)
            return false;
        Term *term = new Term;
        term->SetCoeff(static_cast<int>(coefficient) * sign);
        term->SetExponent(exponent);
        poly.Insert(term);
        spaces(p);
        first = false;
    }
    return !first;
}
int main() {
    Polynomial a, b;
    cout << "Input first polynomial: ";
    if (!InputPolynomial(a))
        return 1;
    cout << "Input second polynomial: ";
    if (!InputPolynomial(b))
        return 1;
    cout << "\nFirst polynomial: ";
    a.PrintList();
    cout << "Second polynomial: ";
    b.PrintList();
    Polynomial sum, difference;
    sum.Add(a);
    sum.Add(b);
    difference.Add(a);
    difference.Sub(b);
    cout << "\nTest Add Function poly1 + poly2: ";
    sum.PrintList();
    cout << "Test Sub Function poly1 - poly2: ";
    difference.PrintList();
}
