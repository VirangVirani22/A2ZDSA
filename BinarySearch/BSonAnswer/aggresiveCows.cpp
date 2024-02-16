#include<bits/stdc++.h>
bool fun(int mid,vector<int> &stalls, int k,int n){
    int cnt = 1,past = stalls[0];
    for(int i=1;i<n;i++){
        if((stalls[i]-past)>=mid){
            // cout<<i<<endl;
            cnt+=1;
            past = stalls[i];
        }
    }
    // cout<<mid<<" "<<cnt<<endl;
    if(cnt>=k) return true;
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //Write your code here.
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int l = 1, r = stalls[n-1] - stalls[0];
    int ans = 1;
    while(l<=r){
        // cout<<l<<" "<<r<<endl;
        int mid = l + (r-l)/2;
        if(fun(mid,stalls,k,n)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    } 
    return ans;
    

}