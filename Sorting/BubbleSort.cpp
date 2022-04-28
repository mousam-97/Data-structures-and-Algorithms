#include <iostream>
using namespace std;

void swap(int *x, int *y){
    int *temp = x;
    x=y;
    y=temp;
}

void BubbleSort(int A[], int n){
    int flag =0;    //using Falg to Make it Adaptive
    for(int i=0; i<n-1; i++){

        flag=0;

        for(int j=0; j<n-1-i; j++){
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
                flag=1;
            }
        }

        if(flag==0){
            break;
        }

    }
}

int main() {
    int A[] = {6,2,4,9,1,5};
    int n=6;
    BubbleSort(A,n);

    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
}