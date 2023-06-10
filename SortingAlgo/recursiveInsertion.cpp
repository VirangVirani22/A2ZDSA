#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void insert(int arr[], int i,int n)
    {
        if(i==n) return;
        int ele = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j]>ele){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1 ] = ele;
        insert(arr,i+1,n);
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        insert(arr,1,n);
    }
};