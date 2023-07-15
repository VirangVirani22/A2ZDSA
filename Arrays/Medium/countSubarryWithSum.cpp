//bruteforce : generate all subarrays 

//optinal : using prefix array 
class Solution{
    public:
    int findSubArraySum(int arr[], int N, int k)
    {
        // code here
        unordered_map <int,int> mp;
        mp[0] = 1;
        int ans=0;
        int presum=0;
        for(  int i=0;i<N;i++){
            presum += arr[i];
            ans += mp[presum - k];
            mp[presum]++;
        }
        return ans;
    }
};