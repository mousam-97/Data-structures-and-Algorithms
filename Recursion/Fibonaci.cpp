#include<iostream>
using namespace std;

int F[10];

int fib1(int n){
    int num1=0, num2=1, sum=0;
    if (n<=1)
        return n;

    for(int i=2; i<=n; i++){
        sum=num1+num2;
        num1=num2;
        num2=sum;
    }

    return sum;
}

int fib2(int n){
    if(n<=1)
        return n;

    return fib2(n-2) + fib2(n-1);
}

int fib3(int n){
    if(n<=1){
        F[n]=n;
        return n;
    }
    
    if(F[n-2]==-1)
        F[n-2]=fib3(n-2);
    if(F[n-1]==-1)
        F[n-1]=fib3(n-1);
    F[n]=F[n-2] + F[n-1];

    return F[n];

}

int main(){
    for(int i=0; i<10; i++){
        F[i]=-1;
    }

    cout<<fib3(4);
}