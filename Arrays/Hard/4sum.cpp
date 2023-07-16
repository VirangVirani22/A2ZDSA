//same as three sum

//i.e four loops --> hashing --.sorting

vector<vector<int>> fourSum(vector<int>& nums, int t) {
    vector<vector<int>> ans;
    int n = nums.size();
     sort(nums.begin(),nums.end());
     for(int i=0;i<n;i++){
         if (i > 0 && nums[i] == nums[i - 1]) continue;
         for(int j=i+1;j<n;j++){
             if (j > i + 1 && nums[j] == nums[j - 1]) continue;
             int target = t -( nums[i] + nums[j]);
             int k = j+1, l=n-1;
             while( k<l){
                 if(nums[k]+nums[l]<target){
                     k++;
                 }else if(nums[k]+nums[l]>target){
                     l--;
                 }else{
                    vector <int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    temp.push_back(nums[l]);
                    ans.push_back( temp);
                    k++,l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                 }
             }
         }
     }
     return ans;
}