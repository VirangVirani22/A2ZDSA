#include<bits/stdc++.h>
int upperbound(int x,vector <int> mat,int col){
    int l = 0, r = col-1;
    int ans = col;
    while(l<=r){
        int mid = l + (r - l)/2;
        if(mat[mid]>x){
            ans = mid;
             r = mid - 1;
            
        }else{
           l = mid + 1;
        }
    }
    return ans;
}
int fun(int mid,vector<vector<int>> &mat, int row, int col){
    int cnt = 0 ;
    for(int i=0;i<row;i++){
        cnt += upperbound(mid,mat[i],col);
    }
    return cnt;
}
int median(vector<vector<int>> &mat, int m, int n) {
    // Write your code here
    int l = INT_MAX, r = INT_MIN;
    int half = (n*m) / 2;
    for(int i=0;i<m;i++) l = min(l,mat[i][0]);
    for(int i=0;i<m;i++) r = max(r,mat[i][n-1]);
    while(l<=r){
        int mid = l + (r-l)/2;
        int lessthanthis = fun(mid,mat,m,n);
        // cout<<mid<<" "<<lessthanthis<<endl;
        if (lessthanthis <= half) {
            l  = mid + 1;
            
        } else {
            r = mid-1;
        }
    }
    return l;
    
}