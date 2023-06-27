//brute-force generate all subarary

class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the function
        int ans = 0; 
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum+=a[j];
                if(sum==k){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    } 

};

//using hashing by storing previous sums for array containing negative numbers this is optimal 

class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the function
        int ans = 0,sum=0; 
        map <int,int> mp;
        for(int i=0;i<n;i++){
           sum+=a[i];
           if(sum==k) ans = max(ans,i+1);
        //   cout<<i<<endl;
        //   for(auto x:mp){
        //       cout<<x.first<<" "<<x.second<<endl;
        //   }
           int rem = sum-k;
           if(mp.find(rem)!=mp.end()){
               int p = mp[rem];
               ans = max(ans,i-p);
           }
           if(mp.find(sum)==mp.end())
           mp[sum] = i;
        }
        return ans;
    } 

};


//for array consists of positive numbers using two pointers
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the function
       
        int i=0,j=0,sum=0,ans=0;
        while(j<n){
            
            while(sum>k && i<=j){
                sum-=a[i];
                i++;
            }
            sum+=a[j];
            if(sum==k){
                ans= max(ans,j-i+1);
            }
            j++;
            
        }
        return ans;
    } 

};

