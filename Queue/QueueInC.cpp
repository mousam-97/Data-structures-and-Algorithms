#include <iostream>
using namespace std;

struct Queue{
    int capacity;
    int front;
    int rear;
    int *Q;
};

void createQueue(struct Queue *q, int s){
    q->capacity=s;
    q->Q = (int *)malloc(q->capacity * sizeof(int));
    q->front=q->rear=-1;
}

void enqueue(struct Queue *q, int x){
    if(q->rear == q->capacity-1){
        cout<<"Queue is full\n";
        return;
    }

    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int dequeue(struct Queue *q){
    if(q->front==q->rear){
        cout<<"Queue is empty\n";
        return -1;
    }
    else{
        q->front++;
        int x = q->Q[q->front];
        return x;
    }
}

void display(struct Queue q){
    if(q.front==q.rear)
        cout<<"Queue is empty\n";
        

    for(int i = q.front+1; i<=q.rear; i++){
        cout<<q.Q[i]<<" ";
    }
    cout<<endl;
}

int main(){
    struct Queue q;
    createQueue(&q,10);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    display(q);

    cout<<dequeue(&q)<<endl;
    display(q);
    cout<<dequeue(&q)<<endl;
    display(q);
     cout<<dequeue(&q)<<endl;
    display(q);
    cout<<dequeue(&q)<<endl;
    display(q);
    cout<<dequeue(&q)<<endl;
}