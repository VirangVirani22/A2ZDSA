//bruteforce : 2 pass 

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg,ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }
        // for(auto x:pos) cout<<x<<" "; cout<<endl;
        // for(auto x:neg) cout<<x<<" "; cout<<endl;
        for(int i=0;i<(nums.size()/2);i++){
            ans[i*2] = pos[i];
            ans[i*2+1] = neg[i];
        }
        return ans;
    }
};

//optimal : in one pass

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n);
        int nextpos = 0,nextneg = 1;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                ans[nextpos] = nums[i];
                nextpos+=2;
            }else{
                ans[nextneg] = nums[i];
                nextneg+=2;
            }
        }
        return ans;
    }
};

//if not equal positives and negatives than 2-pass is the best option

class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector <int> pos,neg;
	    for(int i=0;i<n;i++){
	        if(arr[i]<0) neg.push_back(arr[i]);
	        else pos.push_back(arr[i]);
	    }
	    int possize=pos.size(),negsize = neg.size();
	    int similar = min(possize,negsize);
	    for(int i=0;i<similar;i++){
	        arr[2*i] = pos[i];
	        arr[2*i+1] = neg[i];
	        
 	    }
 	    int remindex = 2*similar;
 	    if(negsize==similar){
 	        for(int i=similar;i<possize;i++){
 	            arr[remindex++] = pos[i];
 	        }
 	    }else{
 	         for(int i=similar;i<negsize;i++){
 	            arr[remindex++] = neg[i];
 	        }
 	    }
	}
};