class Solution {
    int fun(int mid,vector<int>& nums, int th,int n){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=((nums[i]/mid) + ((nums[i]%mid)>0));
        }
        //cout<<mid<<" "<<sum<<endl;
        if(sum<=th) return true;
        return false;
    }
public:
    int smallestDivisor(vector<int>& nums, int th) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int l = 1, r=nums[n-1];
        int ans;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(fun(mid,nums,th,n)){
                ans  = mid;
                r = mid -1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
};