// Find the minimum index of a repeating element in an array
// Input:  { 5, 6, 3, 4, 3, 6, 4 }
// Output: The minimum index of the repeating element is 1

#include<iostream>
using namespace std;
#include<unordered_set>

int func(int A[], int n)
{
    int minIndex = n;
    unordered_set<int> set;

    for(int i=n-1; i>=0; i--)
    {
        if(set.find(A[i]) != set.end())
        {
            minIndex = i;
        }
        else
        {
            set.insert(A[i]);
        }
    }

    return minIndex;
}

int main()
{
    int A[] = {4,5, 6, 3, 4, 3, 6, 4};
    int n = sizeof(A)/sizeof(A[0]);

    int k = func(A,n);

    if(k!=n)
    {
        cout<<"Minimum index is: "<<k;
    }
    else
    {
        cout<<"invalid Input";
    }


}
