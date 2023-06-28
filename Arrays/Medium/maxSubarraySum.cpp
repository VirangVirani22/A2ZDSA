//bruteforce  : o(N^2) generating all subarrays

//kadane's algorithm 
class Solution{

    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long sum = 0, ans = INT_MIN ;
        for(int i=0;i<n;i++){
            sum = max(sum+arr[i],(long long)arr[i]);
            ans = max(ans,sum);
        }
        return ans;
        
    }
};


//if we have to print sub array

class Solution{

    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long sum = 0, ans = INT_MIN ,sti=0,edi=0,fsti=0,fedi=0;
        
        for(int i=0;i<n;i++){
            
           // sum = max(sum+arr[i],(long long)arr[i]);
            if(sum+arr[i]>=arr[i]){
                edi = i;
            }else{
                sti=i;
                edi=i;
            }            
            if(sum>ans){
                fsti=sti;
                fedi=edi;
            }
        }
        for(int i=fsdi;i<=fedi:i++) cout<<arr[i]<<" ";
        
        
    }
};