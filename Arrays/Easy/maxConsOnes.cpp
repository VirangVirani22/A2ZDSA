class Solution
{
    public:
    int maxConsecutiveOnes(int n)
    {
        // code here
        vector <int> v;
        while(n){
            int r = n%2;
            v.push_back(r);
            n = n/2;
        }
        reverse(v.begin(),v.end());
        int ans = 0;
        int cnt = 0;
        int s = v.size();
        for(int i=0;i<s;i++){
            if(v[i]==0){
                cnt=0;
            }else{
               
                    cnt++;
                    ans = max(ans,cnt);
                
            }
        }
        return ans;
    }
};

