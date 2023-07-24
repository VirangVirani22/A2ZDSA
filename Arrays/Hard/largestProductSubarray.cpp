////brute : generate all subrrarrays go from O(N^3) to O(N^2)
//optimal : observation using prefix suffix

int subarrayWithMaxProduct(vector<int> &nums){
	// Write your code here.
	int zros =0 ,pos=0, neg=0;
        int prod = 1;
        for(auto i:nums){
            if(i==0) zros++;
            else if(i<0) neg++;
            else pos++;
            prod = prod *i;

        }
        if(zros==0 && neg==0){
            return prod;
        }
        if(zros==0 && neg%2==0){
            return prod;
        }
        int pre=1,suff=1,ans=0;
        int n = nums.size( );
        for(int i=0;i<n;i++){
           pre = pre * nums[i];
           suff = suff * nums[n-i-1];
           if(pre==0) pre=1;
           if(suff==0) suff=1;
           ans = max(ans,max(pre,suff));
        }
        return ans;
}

//optimal 2: similar to kadane algo 
