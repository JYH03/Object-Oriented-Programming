// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include <cstring>
#include <iostream>
using namespace std;
class Node {
  public:
    char *data;
    Node *next;
    explicit Node(const char *word) : data(new char[strlen(word) + 1]), next(nullptr) {
        strcpy(data, word);
    }
    ~Node() { delete[] data; }
};
int compareLower(const char *a, const char *b) {
    while (*a && *b) {
        unsigned char x = *a++, y = *b++;
        if (x >= 'A' && x <= 'Z')
            x += 32;
        if (y >= 'A' && y <= 'Z')
            y += 32;
        if (x != y)
            return x < y ? -1 : 1;
    }
    return *a ? 1 : (*b ? -1 : 0);
}
void InsertNode(Node *&head, const char *data) {
    Node *node = new Node(data);
    Node **at = &head;
    while (*at && compareLower((*at)->data, data) <= 0)
        at = &(*at)->next;
    node->next = *at;
    *at = node;
}
void InsertWords(Node *&head, char *text) {
    char *p = text;
    while (*p) {
        while (*p == ' ' || *p == '\t')
            ++p;
        if (!*p)
            break;
        char *start = p;
        while (*p && *p != ' ' && *p != '\t')
            ++p;
        if (*p)
            *p++ = '\0';
        InsertNode(head, start);
    }
}

Node *Merge_List(Node *a, Node *b) {
    Node *head = nullptr;
    Node **tail = &head;
    while (a && b) {
        Node *&chosen = compareLower(a->data, b->data) <= 0 ? a : b;
        *tail = chosen;
        chosen = chosen->next;
        tail = &(*tail)->next;
    }
    *tail = a ? a : b;
    return head;
}
int main() {
    Node *a = nullptr, *b = nullptr;
    char first[4096], second[4096];
    cout << "Input list 1: ";
    if (!cin.getline(first, sizeof(first)))
        return 1;
    cout << "Input list 2: ";
    if (!cin.getline(second, sizeof(second)))
        return 1;
    InsertWords(a, first);
    InsertWords(b, second);
    Node *result = Merge_List(a, b);
    cout << "Result: ";
    for (Node *p = result; p; p = p->next) {
        cout << p->data;
        if (p->next)
            cout << ' ';
    }
    cout << '\n';
    while (result) {
        Node *next = result->next;
        delete result;
        result = next;
    }
}
