// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#pragma once
class Node {
    int m_Data;
    Node *m_pNext;
    Node *m_pPrev;

  public:
    Node() : m_Data(0), m_pNext(nullptr), m_pPrev(nullptr) {}
    ~Node() = default;
    void SetData(int n) { m_Data = n; }
    void SetNext(Node *p) { m_pNext = p; }
    void SetPrev(Node *p) { m_pPrev = p; }
    int GetData() const { return m_Data; }
    Node *GetNext() const { return m_pNext; }
    Node *GetPrev() const { return m_pPrev; }
};
class Queue {
    int m_Size, m_NumElement;
    Node *head;
    Node *tail;
    Queue(const Queue &) = delete;
    Queue &operator=(const Queue &) = delete;

  public:
    Queue();
    ~Queue();
    void SetSize(int n);
    bool IsEmpty() const;
    bool IsFull() const;
    bool Push(Node *node);
    Node *Pop();
    void PrintQueue() const;
};
