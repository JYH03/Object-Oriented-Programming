// 수동 배열과 연결 구조를 사용하는 과제 코드. 표준 컨테이너는 사용하지 않는다.
#include <iostream>

#include <ctime>

#include <cstdlib>

using namespace std;

struct Node

{

    int data;

    Node *next;
};

Node *addNode(int data)

{

    Node *newNode = new Node();

    newNode->data = data;

    newNode->next = nullptr;

    return newNode;
}

bool Existence(Node *head, int data)

{

    Node *current = head;

    while (current)

    {

        if (current->data == data)

        {

            return true;
        }

        current = current->next;
    }

    return false;
}

void insertNode(Node *&head, int data)

{

    Node *newNode = addNode(data);

    newNode->next = head;

    head = newNode;
}

void printLinkedList(Node *head)

{

    Node *temp = head;

    while (temp)

    {

        cout << temp->data << " ";

        temp = temp->next;
    }

    cout << endl;
}

Node *randomList()

{

    Node *head = nullptr;

    int count = 0;

    srand(static_cast<unsigned int>(time(0)));

    while (count < 16)

    {

        int randomNumber = rand() % 201;

        if (!Existence(head, randomNumber))

        {

            insertNode(head, randomNumber);

            count++;
        }
    }

    return head;
}

void InsertionSort(Node *&head)

{

    if (!head || !head->next)

        return;

    Node *sorted = nullptr;

    while (head)

    {

        Node *current = head;

        head = head->next;

        if (!sorted || current->data > sorted->data)

        {

            current->next = sorted;

            sorted = current;

        }

        else

        {

            Node *temp = sorted;

            while (temp->next && temp->next->data > current->data)

            {

                temp = temp->next;
            }

            current->next = temp->next;

            temp->next = current;
        }
    }

    head = sorted;
}

int listLength(Node *head)

{

    int length = 0;

    Node *current = head;

    while (current)

    {

        length++;

        current = current->next;
    }

    return length;
}

Node *NodeAt(Node *head, int index)

{

    Node *current = head;

    int currentIndex = 0;

    while (current && currentIndex < index)

    {

        current = current->next;

        currentIndex++;
    }

    return current;
}

Node *Binary_Search(Node *&head, int target)

{

    InsertionSort(head);

    cout << "Sorted List: ";

    printLinkedList(head);

    int low = 0;

    int high = listLength(head) - 1;

    while (low <= high)

    {

        int mid = (low + high) / 2;

        Node *midNode = NodeAt(head, mid);

        if (midNode->data == target)

        {

            return midNode;

        }

        else if (midNode->data < target)

        {

            high = mid - 1;

        }

        else

        {

            low = mid + 1;
        }
    }

    Node *closestNode;

    Node *lowNode = NodeAt(head, low);

    Node *highNode = NodeAt(head, high);

    if (high < 0)

    {

        closestNode = lowNode;

    }

    else if (low >= listLength(head))

    {

        closestNode = highNode;

    }

    else

    {

        closestNode = (llabs(static_cast<long long>(target) - lowNode->data) <=
                       llabs(static_cast<long long>(target) - highNode->data))
                          ? lowNode
                          : highNode;
    }

    if (closestNode->data > target)

    {

        cout << "Node not found, below node does not exist" << endl;

        cout << "Closest node is result " << endl;

        return closestNode;
    }

    cout << "Node not found, below node is result " << endl;

    return closestNode;
}

int main()

{

    Node *head = randomList();

    cout << "List: ";

    printLinkedList(head);

    int target = 0;

    cout << "Write Binary Search: ";

    if (!(cin >> target)) {
        while (head) {
            Node *n = head->next;
            delete head;
            head = n;
        }
        return 1;
    }

    Node *result = Binary_Search(head, target);

    cout << "Result: " << result->data << endl;

    return 0;
}
