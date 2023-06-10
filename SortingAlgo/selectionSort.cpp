#include<bits/stdc++.h>
using namespace std;
//first taught
class Solution
{
    public:
     
    void selectionSort(int arr[], int n)
    {
       for(int i=0;i<n;i++){
           int mn = arr[i],mni = i;
           for(int j=i+1;j<n;j++){
               if(arr[j]<mn){
                   mn = arr[j];
                   mni = j;
               }
           }
           swap(arr[i],arr[mni]);
       }
    }
};

//clean code
class Solution
{
    public:
     
    void selectionSort(int arr[], int n)
    {
       for(int i=0;i<n-1;i++){
           int mni = i;
           for(int j=i+1;j<n;j++){
               if(arr[j]<arr[mni]){
                   mni = j;
               }
           }
           if(mni!=i)
           swap(arr[i],arr[mni]);
       }
    }
};