#include<iostream>
using namespace std;

int func(int n){
    if(n==1){
        return 1;
    }

    else{
    return n + func(n-1);
    }
}

int main(){
    cout<<func(2);
    // cout<<"Hello";
    return 0;
}
