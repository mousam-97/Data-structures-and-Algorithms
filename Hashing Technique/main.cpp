#include <iostream>
using namespace std;
#include "Header/Chains.h"

int Hash(int key)
{
    return key%10;
}

void Insert(Node *H[], int key){
    int index = Hash(key);
    Chains c;
    c.SortedInsert(&H[index], key);
}

int main() {
    Node *HT[10];
    Chains c;

    for(int i=0; i<10; i++)
    {
        HT[i] = NULL;
    }
    
    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);
    Insert(HT, 2);

    Node *t = c.Search(HT[Hash(31)],31);
    cout<<t->data;

}