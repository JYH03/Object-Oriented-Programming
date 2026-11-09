// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include "PolyTerm.h"
#include <climits>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;

Term::Term() {

    m_Coefficient = 0;
    m_Exponent = 0;
    m_pNext = nullptr;
}

Term::~Term() {}

void Term::SetCoeff(int coeff) { m_Coefficient = coeff; }

void Term::SetExponent(int exponent) { m_Exponent = exponent; }

int Term::GetCoeff() { return m_Coefficient; }

int Term::GetExponent() { return m_Exponent; }

void Term::SetNext(Term *pNext) { m_pNext = pNext; }

Term *Term::GetNext() { return m_pNext; }

Polynomial::Polynomial() { m_pHead = nullptr; }

Polynomial::~Polynomial() {
    Term *pTerm = m_pHead;

    while (pTerm != nullptr) {
        Term *pNext = pTerm->GetNext();
        delete pTerm;
        pTerm = pNext;
    }
}

void Polynomial::Insert(Term *pTerm) {
    if (!pTerm)
        return;
    if (pTerm->GetCoeff() == 0) {
        delete pTerm;
        return;
    }

    if (m_pHead == nullptr) {
        m_pHead = pTerm;
        return;
    }

    Term *pCurrent = m_pHead;
    Term *pPrev = nullptr;

    while (pCurrent != nullptr && pCurrent->GetExponent() > pTerm->GetExponent()) {
        pPrev = pCurrent;
        pCurrent = pCurrent->GetNext();
    }

    if (pCurrent != nullptr && pCurrent->GetExponent() == pTerm->GetExponent()) {
        long long combined = static_cast<long long>(pCurrent->GetCoeff()) + pTerm->GetCoeff();
        if (combined < INT_MIN || combined > INT_MAX) {
            delete pTerm;
            throw std::overflow_error("coefficient");
        }
        pCurrent->SetCoeff(static_cast<int>(combined));
        delete pTerm;

        if (pCurrent->GetCoeff() == 0.0) {

            if (pPrev == nullptr) {
                m_pHead = pCurrent->GetNext();
            }

            else {
                pPrev->SetNext(pCurrent->GetNext());
            }
            delete pCurrent;
        }
    }

    else {
        pTerm->SetNext(pCurrent);

        if (pPrev == nullptr) {
            m_pHead = pTerm;
        }

        else {
            pPrev->SetNext(pTerm);
        }
    }
}

void Polynomial::PrintList() {
    Term *pTerm = m_pHead;
    bool isFirstTerm = true;

    while (pTerm != nullptr) {

        if (pTerm->GetCoeff() == 0) {
            pTerm = pTerm->GetNext();
            continue;
        }

        if (!isFirstTerm) {

            if (pTerm->GetCoeff() > 0) {
                cout << " + ";
            }

            else if (pTerm->GetCoeff() < 0) {
                cout << " - ";
            }
        }

        else if (pTerm->GetCoeff() < 0) {
            cout << "-";
        }

        if (pTerm->GetExponent() == 0 || llabs(static_cast<long long>(pTerm->GetCoeff())) != 1) {
            cout << llabs(static_cast<long long>(pTerm->GetCoeff()));
        }

        if (pTerm->GetExponent() != 0) {
            cout << "x";

            if (pTerm->GetExponent() != 1) {
                cout << "^" << pTerm->GetExponent();
            }
        }

        isFirstTerm = false;
        pTerm = pTerm->GetNext();
    }
    if (isFirstTerm)
        cout << 0;
    cout << endl;
}

void Polynomial::Add(Polynomial &poly) {
    if (this == &poly) {
        Polynomial copy;
        copy.Add(poly);
        Add(copy);
        return;
    }
    Term *pTerm = poly.m_pHead;

    while (pTerm != nullptr) {
        Term *newTerm = new Term();
        newTerm->SetCoeff(pTerm->GetCoeff());
        newTerm->SetExponent(pTerm->GetExponent());
        Insert(newTerm);
        pTerm = pTerm->GetNext();
    }
}

void Polynomial::Sub(Polynomial &poly) {
    if (this == &poly) {
        Polynomial copy;
        copy.Add(poly);
        Sub(copy);
        return;
    }
    Term *pTerm = poly.m_pHead;

    while (pTerm != nullptr) {
        Term *newTerm = new Term();
        if (pTerm->GetCoeff() == INT_MIN) {
            delete newTerm;
            throw std::overflow_error("coefficient");
        }
        newTerm->SetCoeff(-pTerm->GetCoeff());
        newTerm->SetExponent(pTerm->GetExponent());
        Insert(newTerm);
        pTerm = pTerm->GetNext();
    }
}
