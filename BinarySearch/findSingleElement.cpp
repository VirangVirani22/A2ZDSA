class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int  n = arr.size();
        if(n==1) return arr[0];
        int l = 0 ,r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(mid==0){
               if(arr[mid]!=arr[mid+1]) return arr[mid];
            }else if(mid==n-1){
                if(arr[mid]!=arr[mid-1]) return arr[mid];
            }
            if(mid!=0 && mid!=n-1 && arr[mid-1]!=arr[mid] && arr[mid+1]!=arr[mid]){
                return arr[mid];
            }
            else if(mid!=0 && arr[mid-1]==arr[mid]){
                if(mid%2==0){
                    r = mid - 1;
                }else{
                    l  = mid + 1;
                }
            }else if(mid!=n-1){
                if(mid%2==0){
                     l  = mid + 1;
                   
                }else{
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
    
};


//removing edge cases
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int  n = arr.size();
        if(n==1) return arr[0];
        if(arr[0]!=arr[1]) return arr[0];
        if(arr[n-1]!=arr[n-2]) return arr[n-1];

        int l = 1 ,r = n-2;
        while(l<=r){
            int mid = l + (r-l)/2;
          
            if(arr[mid-1]!=arr[mid] && arr[mid+1]!=arr[mid]){
                return arr[mid];
            }
            else if(arr[mid-1]==arr[mid]){
                if(mid%2==0){
                    r = mid - 1;
                }else{
                    l  = mid + 1;
                }
            }else{
                if(mid%2==0){
                     l  = mid + 1;
                   
                }else{
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
    
};