#include <bits/stdc++.h>
int fun(int mid,vector<int> a, int k,int n){
    int pastsum = 0;
    int cnt = 1;
    for(int i=0; i<n ; i++){
        // cout<<pastsum<<" "<<cnt<<endl;
        if((pastsum + a[i])<=mid){
            pastsum += a[i];
        }else{
            cnt++;
            pastsum = a[i];
        }
    }
    // cout<<mid<<" "<<cnt<<endl;
    return cnt<=k;
}
int largestSubarraySumMinimized(vector<int> a, int k) {
    // Write Your Code Here
    int n = a.size();
    int mx = INT_MIN;
    int sum  = 0;
    for(int i=0;i<n;i++){
        mx = max(mx,a[i]);
        sum += a[i];
    }
    int l = mx , r = sum,ans;
    while(l<=r){
        int mid  = l+ (r-l)/2;
        if(fun(mid,a,k,n)){
            ans = mid;
            r = mid - 1;

        }else{
            l  = mid +  1;
        }
    }
    return ans;
}