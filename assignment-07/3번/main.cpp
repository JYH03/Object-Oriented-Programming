// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include "Queue.h"
#include <cstring>
#include <iostream>
int main() {
    int size, data;
    std::cout << "Input size: ";
    if (!(std::cin >> size) || size < 0)
        return 1;
    Queue list;
    list.SetSize(size);
    char command[100];
    while (std::cin.width(100), std::cin >> command) {
        if (std::strcmp(command, "exit") == 0)
            break;
        if (std::strcmp(command, "push") == 0) {
            if (!(std::cin >> data))
                return 1;
            if (list.IsFull()) {
                std::cout << "Full Queue.\n";
                continue;
            }
            Node *p = new Node;
            p->SetData(data);
            if (!list.Push(p))
                delete p;
        } else if (std::strcmp(command, "pop") == 0) {
            Node *p = list.Pop();
            if (p) {
                std::cout << p->GetData() << '\n';
                delete p;
            } else
                std::cout << "Empty Queue.\n";
        } else if (std::strcmp(command, "full") == 0)
            std::cout << (list.IsFull() ? "True." : "False.") << '\n';
        else if (std::strcmp(command, "empty") == 0)
            std::cout << (list.IsEmpty() ? "True." : "False.") << '\n';
        else if (std::strcmp(command, "print") == 0)
            list.PrintQueue();
    }
}
