#include<bits/stdc++.h>
using namespace std;

//first taught
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int res[r-l+1];
         int lindex = l;
         int rindex = m+1;
         int k = 0;
         while(lindex<=m && rindex<=r){
             if(arr[lindex]>arr[rindex]){
                 res[k++] = arr[rindex++];
             }else{
                 res[k++] = arr[lindex++];
             }
         }
         while(lindex<=m){
             res[k++] = arr[lindex++];
         }
         while(rindex<=r){
             res[k++] = arr[rindex++];
         }
         k=0;
         for(int i=l;i<=r;i++) arr[i] = res[k++];
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r) return;
        int mid  = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};


//small change
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int res[r-l+1];
         int lindex = l;
         int rindex = m+1;
         int k = 0;
         while(lindex<=m && rindex<=r){
             if(arr[lindex]>arr[rindex]){
                 res[k++] = arr[rindex++];
             }else{
                 res[k++] = arr[lindex++];
             }
         }
         while(lindex<=m){
             res[k++] = arr[lindex++];
         }
         while(rindex<=r){
             res[k++] = arr[rindex++];
         }
         
         for(int i=l;i<=r;i++) arr[i] = res[i-l];
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r) return;
        int mid  = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};