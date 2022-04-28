#include<iostream>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int size;
        int *A;

    public:
        Queue(){front=rear=0; size=10; A = new int[size];}
        Queue(int s){front=rear=0; size=s; A = new int[size];}
        void enqueue(int x);
        int dequeue();
        void display();
};

void Queue::enqueue(int x){
    if((rear+1)%size==front){
        cout<<"Queue is full\n";
        return;
    }

    else{
        rear = (rear+1)%size;
        A[rear]=x;
    }
}

int Queue::dequeue(){
    if(front==rear){
        cout<<"Queue is empty\n";
        return -1;
    }
    else{
        front = (front+1)%size;
        int x = A[front];
        return x;
    }
}

void Queue::display(){
    if(front==rear){
        cout<<"Queue is empty\n";
        return;
    }

    else{
        for(int i=front+1; i!=(rear+1)%size;){
            cout<<A[i]<<" ";
            i=(i+1)%size;
        }

        cout<<endl;
    }
}

int main(){
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();

    cout<<q.dequeue()<<endl;
    q.display();
    cout<<q.dequeue()<<endl;
    q.display();
    cout<<q.dequeue()<<endl;
    q.display();

    q.enqueue(10);
    q.enqueue(20);
    q.display();
    q.enqueue(30);
     q.enqueue(40);



}