#include <iostream>
using namespace std;
#include <vector>

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *&head)
{
    Node *cur = head;

    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void reverse(Node *&head)
{
    Node *cur, *next, *prev;
    cur = head;
    prev = next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = NULL;
    Node *cur;
    for (auto x : arr)
    {
        if (head == NULL)
        {
            head = new Node(x);
            cur = head;
        }
        else
        {
            Node *t = new Node(x);
            cur->next = t;
            cur = cur->next;
        }
    }

    printList(head);
    reverse(head);
    printList(head);
}