class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int ans=INT_MAX;
        int l =0 , r = n - 1;
        while(l<=r){
            int mid = l + (r-l)/2;
            ans = min(ans,arr[mid]);
            if(arr[l]<=arr[mid]){
                ans = min(ans,arr[l]);
                l = mid + 1;
            }
            else {
                ans = min(ans,arr[mid]);
                r = mid - 1;
            }
        }
        return ans;
    }
};

//optimization
class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int ans=INT_MAX;
        int l =0 , r = n - 1;
        while(l<=r){
            int mid = l + (r-l)/2;
            ans = min(ans,arr[mid]);
            if(arr[l]<=arr[mid] && arr[mid]<=arr[r]){
                ans = min(ans,arr[l]);
                break;
            }
            if(arr[l]<=arr[mid]){
              
                l = mid + 1;
            }
            else {
            
                r = mid - 1;
            }
        }
        return ans;
    }
};