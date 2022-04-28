#include<iostream>
using namespace std;

template<class T>
class Queue{
    private:
        int front;
        int rear;
        int size;
        T *A;

    public:
        Queue(){front=rear=-1; size=10; A = new T[size];}
        Queue(int s){front=rear=-1; size=s; A = new T[size];}
        void enqueue(T x);
        T dequeue();
        void display();
};

template<class T>
void Queue<T>::enqueue(T x){
    if(rear==size-1){
        cout<<"Queue is full\n";
        return;
    }

    else{
        rear++;
        A[rear]=x;
    }
}

template<class T>
T Queue<T>::dequeue(){
    if(front==rear){
        cout<<"Queue is empty\n";
        return -1;
    }
    else{
        T x = A[++front];
        return x;
    }
}

template<class T>
void Queue<T>::display(){
    if(front==rear){
        cout<<"Queue is empty\n";
        return;
    }

    else{
        for(int i=front+1; i<=rear; i++){
            cout<<A[i]<<" ";
        }

        cout<<endl;
    }
}

int main(){
    Queue<char> q;
    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');
    q.display();

    cout<<q.dequeue()<<endl;
    q.display();
    cout<<q.dequeue()<<endl;
    q.display();
    cout<<q.dequeue()<<endl;
    q.display();

}