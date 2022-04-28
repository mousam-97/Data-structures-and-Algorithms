#include <iostream>
using namespace std;

#ifndef Chains_h
#define Chains_h

class Node{
 public:
    int data;
    Node *next;
};

class Chains {
 public:
    void SortedInsert(Node **H, int key);
    Node *Search(Node *p, int key);
};

void Chains::SortedInsert(Node **H, int key){
    Node *p = *H, *t, *q;

    t = new Node;
    if(!t){
        cout<<"Memory Error";
        return;
    }

    t->data=key;
    t->next = NULL;

    if(*H==NULL){
        *H = t;
    }
    else{
        while(p && p->data < key){
            q=p;
            p=p->next;
        }
        if(p==*H){
            t->next = p;
            *H = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }

}

Node* Chains::Search(Node *p, int key) {
    while(p!=NULL){
        if(p->data == key)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}

#endif
