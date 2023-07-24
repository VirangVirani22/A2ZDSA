//brute : generate all subrrarrays go from O(N^3) to O(N^2)
//optimal : 
class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        map <int,int> mp;
        mp[0] = -1;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(mp.find(sum)!=mp.end()){
                
                ans = max(ans,i-mp[sum]);
                
            }
            else{
                mp[sum] = i;
            }
        }
        return ans;
    }
};