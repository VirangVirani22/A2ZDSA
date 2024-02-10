class Solution {
    pair<int,int> mm(vector<int>& bloom, int n){
        int mn = INT_MAX, mx = INT_MIN;
        for(int i=0;i<n;i++){
            mn = min(mn,bloom[i]);
            mx = max(mx,bloom[i]);
        }
        return make_pair(mn,mx);
    }
    bool fun(int mid,vector<int>& bloom, int m, int k,int n){
        int cnt  = 0;
        int prevcnt =  0;
        for(int i=0;i<k-1;i++){
            
            if(bloom[i]<=mid)
                prevcnt+=1;
            else{
                 prevcnt=0;
             }  
        }
      
        for(int i=k-1;i<n;i++){
          if(bloom[i]<=mid){
              prevcnt+=1;
            }
             else{
                 prevcnt=0;
             }   
            if(prevcnt==k){
              cnt++;
              prevcnt=0;
            }
           
        }
        //cout<<mid<<" "<<cnt<<endl;
        if(cnt>=m) return true;

        return false;
    }
public:
    int minDays(vector<int>& bloom, int m, int k) {
        int n = bloom.size();
        pair <int,int> p  = mm(bloom,n);
        int l = p.first;
        
        int r = p.second;
        if((long long)k*m>n) return -1;
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(fun(mid,bloom,m,k,n)){
                ans  = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};