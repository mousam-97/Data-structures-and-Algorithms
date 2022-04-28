#include <iostream>
using namespace std;

// creating a Node structure
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

// creating a list using array
void createList(int A[], int n)
{
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[0];
    t->next = NULL;
    first = last = t;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// function to display the linked list
void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

// function to display the linkedlist Recursively
void RDisplay(struct Node *p)
{
    if (p != NULL)
    {

        RDisplay(p->next);
        cout << p->data << " ";
    }
}

// count the no. of nodes in a linked list
int count(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

// count the number of nodes in a linked list reccursively
int Rcount(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + Rcount(p->next);
    }
}

// sum of nodes data in a linked list.
int sum(struct Node *p)
{
    int s = 0;
    while (p != NULL)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}

// find the sum of nodes data in a linked list recursively.
int Rsum(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return p->data + Rsum(p->next);
    }
}

// find the maximum item in a linked list.
int Max(struct Node *p)
{
    int max = INT32_MIN;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

// find the maximum item in a linked list recursively.
int Rmax(struct Node *p)
{
    int x = 0;
    if (p == NULL)
    {
        return INT32_MIN;
    }
    else
    {
        x = Rmax(p->next);
        return x > p->data ? x : p->data;
    }
}

// this function needs to be rechecked.
struct Node *Lsearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }

    return NULL;
}

// search an item in a linked list recursively.
struct Node *Rsearch(struct Node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }

    if (p->data == key)
    {
        return p;
    }
    return Rsearch(p->next, key);
}

// insert an item in a linked list after a certain index.
void insert(struct Node *p, int index, int x)
{

    if (index < 0 || index > count(p))
    {
        return;
    }

    struct Node *t = new Node;
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1 && p; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

// insert an item in a sorted linked list.
void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

// delete an item from the list.
int Delete(struct Node *p, int index)
{
    if (index < 1 || index > count(p))
    {
        return -1;
    }

    struct Node *q = NULL;
    int x;
    if (index == 1)
    {
        q = first;
        first = first->next;
        x = q->data;
        delete q;
        return x;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        x = p->data;
        q->next = p->next;
        delete p;
        return x;
    }
}

// to check if the list is sorted.
int isSorted(struct Node *p)
{
    int x = INT16_MIN;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

// to delete duplicate items in a list.
void deleteDuplicate(struct Node *p)
{
    struct Node *q = first->next;
    while (q)
    {
        if (q->data != p->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

// reverse a list by changing the values of the node.
void Reverse1(struct Node *p)
{
    int *A = (int *)malloc(sizeof(int) * count(p));
    struct Node *q = p;
    int i = 0;
    while (q)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    i--;
    q = p;
    while (q)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

// reverse a list by changing the links between the nodes.
void Reverse2(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// reverse a linked list recursively.
void Reverse3(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

int main()
{
    // struct Node *temp;
    int A[] = {10, 20, 30, 40, 50};
    createList(A, 5);
    Reverse3(NULL, first);
    display(first);
}