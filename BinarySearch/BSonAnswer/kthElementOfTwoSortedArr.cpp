#include <bits/stdc++.h>
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here
    
    if(m>n) return kthElement(arr2,arr1,m,n,k);
    int tot  = n  + m;
    int l = max(0,k-m), r = min(n,k);
    while(l<=r){
        int mid1 = l + (r- l)/2;
        int mid2 = k - mid1;
        //cout<<l<<" "<<r<<" "<<mid1<<" "<<mid2<<endl;
        int l1 = INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
        if(mid1>0) l1 = arr1[mid1-1];
        if(mid2>0) l2 = arr2[mid2-1];
        if(mid1<n) r1 = arr1[mid1];
        if(mid2<m) r2 = arr2[mid2];
        // cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<endl;
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }else if(l1>r2){
            r = mid1 -1 ;
        }else if(l2>r1){
            l = mid1 +1;
        }
    }
    return 0;
}