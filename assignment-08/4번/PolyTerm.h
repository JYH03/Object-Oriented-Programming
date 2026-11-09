// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#pragma once
class Term {
    int m_Coefficient, m_Exponent;
    Term *m_pNext;

  public:
    Term();
    ~Term();
    void SetCoeff(int);
    void SetExponent(int);
    int GetCoeff();
    int GetExponent();
    void SetNext(Term *);
    Term *GetNext();
};
class Polynomial {
    Term *m_pHead;
    Polynomial(const Polynomial &) = delete;
    Polynomial &operator=(const Polynomial &) = delete;

  public:
    Polynomial();
    ~Polynomial();
    void Insert(Term *);
    void PrintList();
    void Add(Polynomial &);
    void Sub(Polynomial &);
};
