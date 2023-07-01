class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans=0,mn=INT_MAX;
        for(int i=0;i<p.size();i++)
        {
            mn=min(mn,p[i]);
            ans=max(ans,p[i]-mn);
        }
        return ans;
    }
};