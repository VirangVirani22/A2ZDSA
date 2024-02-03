class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n -1;
        if(n==1) return 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mid==0){
                if(arr[mid]>arr[mid+1]){
                    return mid;
                }else{
                    l = mid + 1;
                }
            }else if(mid==n-1){
                if(arr[mid]>arr[mid-1]){
                    return mid;
                }else{
                    r = mid -1;
                }
            }
            else if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }else if(arr[mid-1]<arr[mid]){
                l = mid + 1;
            }else{
                r  = mid -1;
            }
        }
        return -1;
        
    }
};

//removing edge cases
class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        
        if(n==1) return 0;
        if(arr[0]>arr[1]) return 0;
        if(arr[n-1]>arr[n-2]) return n-1;
        int l = 1, r = n -2;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }else if(arr[mid-1]<arr[mid]){
                l = mid + 1;
            }else{
                r  = mid -1;
            }
        }
        return -1;
        
    }
};