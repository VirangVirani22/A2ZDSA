#include<bits/stdc++.h>
int findKRotation(vector<int> &arr){
    // Write your code here.
    int n = arr.size();  
    int  l = 0, r  = n - 1;
    int mn =  INT_MAX;
    int ind = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[l]<=arr[mid]){
            if(mn>arr[l]){
                mn = arr[l];
                ind  = l;
            }
            l = mid + 1 ;
        }else{
             if(mn>arr[mid]){
                mn = arr[mid];
                ind  = mid;
            }
            r = mid - 1;
        }
    }  
    return ind;
}