#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

};

class Chains {
    public:
        void SortedInsert(Node **H, int key);
        Node *Search(Node *H, int key);
};

void Chains::SortedInsert(Node **H, int key){
    Node *t,*p,*q;
    t = new Node;
    if(!t){
        cout<<"Memory Error";
        return;
    }

    t->data = key;
    t->next = NULL;

    p = *H;
    if(*H == NULL){
        *H = t;
    }
    else {
        while(p && p->data<key){
            q=p;
            p=p->next;
        }
        if(p == *H){
            t->next = p;
            *H = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

int Hash(int key){
    return key % 10;
}

void Insert(Node *HT[], int key){
    int index = Hash(key);
    Chains c;
    c.SortedInsert(&HT[index], key);
}

int main(){
    Node *HT[10];

    for(int i=0; i<10; i++){
        HT[i] = NULL;
    }

    Insert(HT,12);
    Insert(HT,22);
    Insert(HT,42);
}