#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for(int i=1;i<n;i++){
            int j=i-1;
            int ele = arr[i];
            while(j>=0 && arr[j]>ele){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = ele;
        }
    }
};