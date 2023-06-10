#include<bits/stdc++.h>
using namespace std;


//first element as pivot
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low<high){
            int  p = partition(arr,low,high);
            quickSort(arr,low,p-1);
            quickSort(arr,p+1,high);
            
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[low];
        int i =low;
        int j = high;
        while(i<j){
            while(i<=high && arr[i]<=pivot) i++;
            while(j>=low && arr[j]>pivot) j--;
            if(i<j) swap(arr[i],arr[j]);
        }
        swap(arr[j],arr[low]);
        return j;
       // Your code here
    }
};

//last element as pivot
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low<high){
            int  p = partition(arr,low,high);
            quickSort(arr,low,p-1);
            quickSort(arr,p+1,high);
            
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i =low;
        for(int j=i;j<=high-1;j++){
            if(arr[j]<=pivot){
                swap(arr[j],arr[i]);
                i++;
            }
        }
        swap(arr[i],arr[high]);
        return i;
         
       // Your code here
    }
};
