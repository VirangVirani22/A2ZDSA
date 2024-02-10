#define ll long long
class Solution {
    int fun(ll mid,vector<int>& piles, int h,int n){
        ll sum = 0;
        for(int i=0;i<n;i++){
            if(piles[i]<=mid){
                sum++;
            }else{
                ll t = ( (piles[i]/mid) + ((piles[i]%mid)>0) );
                // cout<<t<<endl;
                sum += t;

                
            }
            // cout<<i<<" "<<sum<<endl;
        }
        // cout<<mid<<" "<<sum<<endl;
        if(sum<=h) return true;
        return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n = piles.size();
         ll l = 1;
        ll r = piles[n-1];
        ll ans = r;
        while(l<=r){
            ll mid = l + (r-l)/2;
            if(fun(mid,piles,h,n)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};