#include <bits/stdc++.h>
int fun(int mid,vector<int>& arr, int n, int m){
    int cnt = 1;
    int pastsum = 0;
    for(int i=0; i<n ; i++){
        // cout<<pastsum<<" "<<cnt<<endl;
        if((pastsum + arr[i])<=mid){
            pastsum += arr[i];
        }else{
            cnt++;
            pastsum = arr[i];
        }
    }
    // cout<<mid<<" "<<cnt<<endl;
    return cnt<=m;
}
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    int mx = INT_MIN, sum = 0;
    for(int i=0;i<n;i++){
        mx = max(mx,arr[i]);
        sum += arr[i];
    }
    if(m>n) return -1;
    int l = mx , r = sum,ans = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        int res = fun(mid,arr,n,m);
        if(res){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    // if(ans==INT_MAX) return -1;
    return ans;
}