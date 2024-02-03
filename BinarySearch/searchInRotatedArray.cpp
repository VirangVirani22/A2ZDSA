//without duplicates
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(nums[mid]==target) return mid;
            if(nums[l]<=nums[mid]){
                if(target>=nums[l] && target<=nums[mid])
                    r = mid -1;
                else
                    l = mid+1;
            }
            else {
                if(target>=nums[mid] && target<=nums[r])
                    l = mid+1;
                else
                    r = mid -1;
                    
            }
        }
        return -1;
    }
};

//with duplicates
class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0 , r = n -1 ;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(arr[mid]==target) return true;
            if(arr[mid]==arr[l] && arr[mid]==arr[r]) {
                l++,r--;
                continue;
            }
            if(arr[l]<=arr[mid]){
                if(arr[l]<=target && arr[mid]>=target) r = mid - 1 ;
                else l = mid + 1 ;
            }else{
                if(arr[mid]<=target && arr[r]>=target) l = mid + 1;
                else r = mid - 1;
            }
           

        }
         return false;
    }
};