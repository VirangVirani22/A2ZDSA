//brute-force : O(N^2)

//optimal

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector <int> ans;
        int maxtill = 0;
        for(int i=n-1;i>=0;i--){
            if(a[i]>=maxtill){
                ans.push_back(a[i]);
            }
            maxtill = max(maxtill,a[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};