//bruteforce : O(N^2)
//optimal : mergesort approch
class Solution {
  public:
    void merge(vector<int> &arr, long long l, long long m, long long r)
    {
         // Your code here
         long long res[r-l+1];
         long long lindex = l;
         long long rindex = m+1;
         long long k = 0;
         while(lindex<=m && rindex<=r){
             if(arr[lindex]>arr[rindex]){
                 res[k++] = arr[rindex++];
             }else{
                 res[k++] = arr[lindex++];
             }
         }
         while(lindex<=m){
             res[k++] = arr[lindex++];
         }
         while(rindex<=r){
             res[k++] = arr[rindex++];
         }
         
         for(int i=l;i<=r;i++) arr[i] = res[i-l];
    }
    long long  count(vector<int> &arr, long long l, long long m, long long r){
        long long cnt=0;
        long long sec=m+1;
        for(int i=l;i<=m;i++){
            while(sec<=r &&  arr[i] > ( 2* (long long)arr[sec] ) ) sec++;
            cnt+=(long long)(sec-(m + 1));
        }
        return cnt;
    }
    long long  mergeSort(vector<int> &arr, long long l, long long r)
    {
        //code here
        long long cnt=0;
        if(l>=r) return cnt;
        long long mid  = (l+r)/2;
       cnt += mergeSort(arr,l,mid);
        cnt += mergeSort(arr,mid+1,r);
        cnt += count(arr,l,mid,r);
        merge(arr,l,mid,r);
        return cnt;
    }
    int countRevPairs(int  n, vector<int> arr) {
        // Code here
        return mergeSort(arr,0,n-1);
        //for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        
    }
};