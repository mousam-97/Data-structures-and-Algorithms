//Stack using Generic Class//
#include <iostream>
using namespace std;
#include<string.h>

template <class T>
class Stack {
  private:
    int capacity;
    int top;
    T *A;
  
  public:
    Stack();
    Stack(int c);
    void display();
    void push(T num);
    T pop();
    T peek();
    int isEmpty();
    int isFull();
};

template <class T>
Stack<T>::Stack(){
  capacity=10;
  top=-1;
  A = new T[capacity];
}

template <class T>
Stack<T>::Stack(int c){
  capacity=c;
  top=-1;
  A = new T[capacity];
}

template <class T>
void Stack<T>::display(){
  if(isEmpty()){
    cout<<"Stack is empty\n";
    return;
  }

  for(int i=top; i>=0; i--){
    cout<<A[i]<<" ";
  }
  cout<<endl;
}

template <class T>
void Stack<T>::push(T num){
  if(isFull()){
    cout<<"stack is full";
    return;
  }

  A[++top]=num;

}

template <class T>
T Stack<T>::pop(){
  if(isEmpty()){
    cout<<"stack is empty";
    return -1;
  }

  T x = A[top--];
  return x;
}

template <class T>
int Stack<T>::isEmpty(){
  return top==-1;
}

template <class T>
int Stack<T>::isFull(){
  return top==(capacity-1);
}

template <class T>
T Stack<T>::peek(){
  if(top==-1){
    cout<<"stack is empty\n";
    return -1;
  }
  return A[top];
}



int isOperand(char ch){
  if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
      return 0;
  }
  else  
    return 1;
}

int pre(char ch){
  if(ch=='+' || ch=='-' )
    return 1;

  else if(ch=='*' || ch=='/' )
    return 2;

    
  return 0;
}

char *toPostfix(char arr[]){
  int i=0,j=0;
  
  Stack<char> s(strlen(arr)+2);
  // s.push('#');
  char *postfix = new char[strlen(arr)+2];

  while(arr[i]!='\0'){
    if(isOperand(arr[i])){
      postfix[j++]=arr[i++];
    }
    else{
      if(pre(arr[i])>pre(s.peek())){
        s.push(arr[i++]);
      }
      else{
        postfix[j++] = s.pop();

      }
    }
  }

  while(!s.isEmpty()){
    postfix[j++]=s.pop();
  }

  postfix[j] = '\0';

  return postfix;


}

char opposeOf( char ch){
  switch (ch){
  case '(':
    return ')';
    break;
  
  case '[':
    return ']';
    break;
  case '{':
    return '}';
    break;
  
  case '<':
    return '>';
    break;
  
  default:
    break;
  }

}


int ParentheisMatching(char arr[]){
  Stack<char> s(strlen(arr));

  for(int i=0; arr[i]!='\0';i++){
    if(arr[i]=='(' || arr[i]=='[' || arr[i]=='{' ){
      s.push(arr[i]);
    }
    else if(arr[i]==')' || arr[i]==']' || arr[i]=='}'){
      if(s.isEmpty())
        return 0;
      
      else
      {
          char x = s.pop();
          if(arr[i]!=opposeOf(x))
            return 0;

      }
      
    }
  }

  if(s.isEmpty())
    return 1;

  else
    return 0;
  
}


int postfixResult(char arr[]){
  Stack<int> s;
  for(int i=0; arr[i]!='\0';i++){
    if(isOperand(arr[i])){
      s.push(arr[i]-'0');
    }
    else{
      int x1,x2,r;
      x2=s.pop();
      x1=s.pop();
      switch(arr[i]){
        case '+': r=x1+x2;
              break;
        case '-': r=x1-x2;
              break;
        case '*': r=x1*x2;
              break;
        case '/': r=x1/x2;
              break;
      }
      s.push(r);
    }
  }

  return s.pop();
}

int func(char arr[]){
  Stack<char> s(strlen(arr));
  int count=0;

  for(int i=0; arr[i]!='\0';i++){
    if(arr[i]=='<'){
      s.push(arr[i]);
    }
    else if(arr[i]=='>' && !s.isEmpty()){
      
          char x = s.pop();
          if(arr[i]==opposeOf(x))
            count+=2;

      }
      
    }
    return count;
}

  

int main(){
  char arr[]="><";
  cout<<func(arr);


}