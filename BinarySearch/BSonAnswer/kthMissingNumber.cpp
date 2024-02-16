//O(n)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]<=k) k++;
            else break;
        }
        return k;
    }
};
//Binary serach 
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, r  = n -1;
        while(l<=r){
            int mid = l + (r - l)/2;
            int missing = arr[mid] - (mid+1);
            if(missing<k) l = mid + 1;
            else r = mid - 1;
        }
        /*
        .....high low ....
        arr[high] + more
        arr[high] + (k-missing)
        arr[high] + (k - (arr[high] - (high + 1)))
        arr[high] + k - arr[high] + high + 1
        k + high + 1
        k + low
        */
        return k + l;
    }
};