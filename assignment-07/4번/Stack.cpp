// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include "Stack.h"
#include <iostream>
Stack::Stack() : m_Size(0), m_NumElement(0), head(nullptr), tail(nullptr) {}
Stack::~Stack() {
    while (head) {
        Node *n = head->GetNext();
        delete head;
        head = n;
    }
}
void Stack::SetSize(int n) { m_Size = n < 0 ? 0 : n; }
bool Stack::IsEmpty() const { return m_NumElement == 0; }
bool Stack::IsFull() const { return m_NumElement >= m_Size; }
bool Stack::Push(Node *p) {
    if (!p || IsFull())
        return false;
    p->SetNext(nullptr);
    p->SetPrev(tail);
    if (tail)
        tail->SetNext(p);
    else
        head = p;
    tail = p;
    ++m_NumElement;
    return true;
}
Node *Stack::Pop() {
    if (IsEmpty())
        return nullptr;
    Node *p = tail;
    tail = p->GetPrev();
    if (tail)
        tail->SetNext(nullptr);
    else
        head = nullptr;
    p->SetNext(nullptr);
    p->SetPrev(nullptr);
    --m_NumElement;
    return p;
}
void Stack::PrintStack() const {
    for (Node *p = head; p; p = p->GetNext())
        std::cout << p->GetData() << ' ';
    std::cout << '\n';
}
