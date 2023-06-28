//brute force - O(N^2)

//using hashing

class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    
	    map <int,int> mp;
	    for(int i=0;i<n;i++){
	        if(mp.find(x-arr[i])!=mp.end()) return true;
	        mp[arr[i]] = i;
	        
	    }
	    return false;
	}
};

//using sorting  + two pointer

class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    
	    sort(arr,arr+n);
	    int i=0,j=n-1;
	    while(i<j){
	        int sum  = arr[i] + arr[j];
	        if(sum==x) return true;
	        else if(sum<x) i++;
	        else j--;
	    }
	    return false;
	}
};

//if asked number of pairs/return all indices than use hashing method 
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        map<int,int> mp;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(mp.find(k-arr[i])!=mp.end()){
                ans += mp[k-arr[i]];
            }
            if(mp.find(arr[i])==mp.end()) mp[arr[i]] = 1;
            else mp[arr[i]]++;
        }
        return ans;
    }
};

//gfg problem in sheet
class Solution{
    public:
    vector<pair<int,int>> allPairs(int a[], int b[], int n, int m, int x)
    {
        // Your code goes here  
       vector <pair<int,int> > ans;
       map <int,int> mp;
       for(int i=0;i<n;i++){
           mp[a[i]]++;
       }
       for(int i=0;i<m;i++){
           if(mp.find(x-b[i])!=mp.end()){
               ans.push_back({x-b[i],b[i]});
           }
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};