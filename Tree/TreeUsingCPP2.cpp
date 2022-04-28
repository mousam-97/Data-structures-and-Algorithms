#include <iostream>
using namespace std;
#include <queue>

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};

class Stack
{
    int size;
    int top;
    Node **A;

public:
    Stack()
    {
        size = 10;
        top = -1;
        A = new Node *[size];
    }
    Stack(int size)
    {
        this->size = size;
        top = -1;
        A = new Node *[this->size];
    }
    void push(Node *x);
    Node *pop();
    int isEmpty() { return top == -1; }
};

void Stack::push(Node *x)
{
    if (top == size - 1)
    {
        cout << "Stack is Full ";
    }
    else
    {
        top++;
        A[top] = x;
    }
}

Node *Stack::pop()
{
    if (top == -1)
    {
        cout << "Stack is empty";
        return NULL;
    }
    else
    {
        Node *t = A[top];
        top--;
        return t;
    }
}

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q;

public:
    Queue()
    {
        size = 10;
        front = rear = 0;
        Q = new Node *[size];
    }
    Queue(int size)
    {
        this->size = size;
        front = rear = 0;
        Q = new Node *[this->size];
    }
    void enqueue(Node *x);
    Node *dequeue();
    int isEmpty() { return front == rear; }
};

void Queue::enqueue(Node *x)
{
    if ((rear + 1) % size == front)
    {
        cout << "Queue is full";
    }
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    if (front == rear)
    {
        cout << "Queue is empty";
        return NULL;
    }
    else
    {
        Node *t;
        front = (front + 1) % size;
        t = Q[front];
        return t;
    }
}

class Tree
{
public:
    Node *root;
    Tree() { root = NULL; }
    void createTree();
    void preOrder(Node *p);
    void postOrder(Node *p);
    void inOrder(Node *p);
    void IPreorder(Node *p);
    void IInorder(Node *p);
    void levelorder(Node *p);
    int count(Node *p);
    int height(Node *p);
    int maxElement(Node *p);
    int ImaxElement(Node *p);
    int findElement(Node *p, int data);
};

void Tree::createTree()
{
    int x;
    Node *t, *p;
    Queue q(100);
    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter Left child of " << p->data << " :";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << " :";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preOrder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void Tree::postOrder(Node *p)
{
    if (p)
    {

        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data << " ";
    }
}

void Tree::inOrder(Node *p)
{
    if (p)
    {

        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

void Tree::IPreorder(Node *p)
{
    Stack stk(100);
    while (p || !stk.isEmpty())
    {
        if (p)
        {
            cout << p->data << " ";
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.pop();
            p = p->rchild;
        }
    }
}

void Tree::IInorder(Node *p)
{
    Stack stk(100);
    while (p || !stk.isEmpty())
    {
        if (p)
        {
            stk.push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}

void Tree::levelorder(Node *p)
{
    Queue q;
    cout << p->data << " ";
    q.enqueue(p);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        if (p->lchild)
        {

            cout << p->lchild->data << " ";
            q.enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            q.enqueue(p->rchild);
        }
    }
}

int Tree::count(Node *p)
{
    if (p)
    {
        return count(p->lchild) + count(p->rchild) + 1;
    }
    else
    {
        return 0;
    }
}

int Tree::height(Node *p)
{
    int x = 0, y = 0;
    if (p == NULL)
    {
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

int Tree::maxElement(Node *p)
{
    int x = 0, y = 0;
    int max;
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        x = maxElement(p->lchild);
        y = maxElement(p->rchild);

        if (x == 0 && y == 0)
        {
            return p->data;
        }
        else if (x > y)
        {
            max = x;
        }
        else
        {
            max = y;
        }

        return p->data > max ? p->data : max;
    }
}

int Tree::ImaxElement(Node *p)
{
    Queue q(100);
    Node *t;
    int max = INT32_MIN;
    q.enqueue(p);
    while (!q.isEmpty())
    {
        t = q.dequeue();
        if (t->data > max)
        {
            max = t->data;
        }
        if (t->lchild)
        {
            q.enqueue(t->lchild);
        }
        if (t->rchild)
        {
            q.enqueue(t->rchild);
        }
    }
    return max;
}

int Tree::findElement(Node *p, int data)
{
    int x = 0, y = 0;
    if (p == NULL)
    {
        return 0;
    }

    if (p->data == data)
    {
        return 1;
    }
    else
    {
        x = findElement(p->lchild, data);
        y = findElement(p->rchild, data);
        if (x == 1 || y == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    Tree t;
    t.createTree();
}
