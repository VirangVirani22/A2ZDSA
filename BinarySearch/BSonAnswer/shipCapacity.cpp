class Solution {
    bool fun(int mid,vector<int>& weights, int days,int n){
       int cnt  = 1;
       long long sum = 0;
       for(int i=0;i<n;i++){
        //    cout<<i<<" "<<sum<<endl;
           if((sum + weights[i])<=mid ){
               sum += weights[i];
           }else{
            //    cout<<i<<endl;
               cnt++;
               sum = weights[i];
           }
       }
    //    if(sum>0) cnt++;
    //    cout<<mid<<" "<<cnt<<endl;
       if(cnt<=days) return true;
       return false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n  = weights.size(),ma;
        long long sum  = 0;
        // sort(weights.begin(),weights.end());
        for(int i = 0;i<n;i++){
            sum += weights[i];
            ma = max(ma,weights[i]);
        }
        long long l  = ma, r = sum, ans = sum;
        while(l<=r){
            long long mid= l  + (r-l)/2;
            if(fun(mid,weights,days,n)){
                ans = mid;
                r  = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};