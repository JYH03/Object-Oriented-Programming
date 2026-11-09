// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include "Queue.h"
#include <iostream>
Queue::Queue() : m_Size(0), m_NumElement(0), head(nullptr), tail(nullptr) {}
Queue::~Queue() {
    while (head) {
        Node *n = head->GetNext();
        delete head;
        head = n;
    }
}
void Queue::SetSize(int n) { m_Size = n < 0 ? 0 : n; }
bool Queue::IsEmpty() const { return m_NumElement == 0; }
bool Queue::IsFull() const { return m_NumElement >= m_Size; }
bool Queue::Push(Node *p) {
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
Node *Queue::Pop() {
    if (IsEmpty())
        return nullptr;
    Node *p = head;
    head = p->GetNext();
    if (head)
        head->SetPrev(nullptr);
    else
        tail = nullptr;
    p->SetNext(nullptr);
    p->SetPrev(nullptr);
    --m_NumElement;
    return p;
}
void Queue::PrintQueue() const {
    for (Node *p = head; p; p = p->GetNext())
        std::cout << p->GetData() << ' ';
    std::cout << '\n';
}
