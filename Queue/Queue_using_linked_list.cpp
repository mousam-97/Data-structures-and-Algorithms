#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if(!temp){
        cout<<"Queue is full\n";
    }
    else{
        temp->data=x;
        temp->next=NULL;
        if(front==NULL){
            front=rear=temp;
        }
        else{
            rear->next=temp;
            rear=rear->next;
        }
    }
}

int dequeue(){
    if(front==NULL){
        cout<<"Queue is empty\n";
        return -1;
    }
    else{
        struct Node *temp=front;
        int x = temp->data;
        front=front->next;
        free(temp);
        return x;
    }
}

void display(){
    struct Node *cur  = front;
    while(cur!=NULL){
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    cout<<endl;
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();
    enqueue(60);
    display();
    cout<<dequeue()<<endl;
    display();
    cout<<dequeue()<<endl;
    display();
    dequeue();
    dequeue();
    dequeue();
   
    display();
}   