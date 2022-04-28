// Node, Queue, create, enqueue, dequeue, isEmpty

#include<iostream>
using namespace std;

struct Node{
  struct Node *lchild;
  int data;
  struct Node *rchild;
};

struct Queue{
  int size;
  int front;
  int rear;
  struct Node **Q;
};

void create(struct Queue *q, int size){
  q->size = size;
  q->front = q->rear = 0;
  q->Q =(struct Node **)malloc(q->size * sizeof(Node *));
}

void enqueue(struct Queue *q, struct Node *x){
  if((q->rear+1)%q->size == q->front){
    cout<<"Queue is Full";
  }
  else{
    q->rear = (q->rear + 1)%(q->size);
    q->Q[q->rear] = x;
  }
}

Node * dequeue(struct Queue *q){
  if(q->front == q->rear){
    cout<<"Queue is Empty";
    return NULL;
  }
  else{
    q->front = (q->front+1) % q->size;
    struct Node *t = q->Q[q->front];   
    return t;
  }
}

int isEmpty(struct Queue q){
  return q.front == q.rear;
}

//Create Tree, preorder, inorder, postorder traversal.

struct Node *root = NULL;

void createTree(){
  struct Node *p, *t;
  int x;
  Queue q;
  create(&q,100);

  cout<<"Enter Root value: "<<endl;
  cin>>x;
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = x;
  root->lchild = root->rchild = NULL;
  enqueue(&q,root);

  while(!isEmpty(q)){
    p = dequeue(&q);
    cout<<"Please enter the left child value for "<<p->data<<endl;
    cin>>x;
    if(x!=-1){
      t = (struct Node *)malloc(sizeof(struct Node));
      t->lchild = t->rchild = NULL;
      t->data = x;
      p->lchild = t;
      enqueue(&q, t);
    }
    cout<<"Please enter the right child value for "<<p->data<<endl;
    cin>>x;
    if(x!=-1){
      t = (struct Node *)malloc(sizeof(struct Node));
      t->lchild = t->rchild = NULL;
      t->data = x;
      p->rchild = t;
      enqueue(&q, t);
    }
  }  
}

void preorderTraversal(struct Node *x){
  if(x){
    cout<<x->data<<" ";
    preorderTraversal(x->lchild);
    preorderTraversal(x->rchild);
  }
}

int main(){
  createTree();
  preorderTraversal(root);

}