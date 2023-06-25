//largest element in array
//bruteforce : sorting
class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int mx = INT_MIN;
        for(auto x:arr) mx= max(mx,x);
        return mx;
    }
};

//second largest
//bruteforce : sorting


//2-pass
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int mx  = INT_MIN;
	    for(int i=0;i<n;i++){
	        mx = max(mx,arr[i]);
	    }
	    int smax = -1;
	    for(int i=0;i<n;i++){
	        if(arr[i]!=mx) smax = max(smax,arr[i]);
	    }
	    return smax;
	}
};

//1-pass
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int mx  = INT_MIN;
	    int smax = -1;
	    for(int i=0;i<n;i++){
	       if(arr[i]>mx){
	           smax = mx;
	           mx = arr[i];
	       }else if(arr[i]>smax && arr[i]!=mx){
	           smax = arr[i];
	       }
	    }
	    return smax == INT_MIN ? -1 : smax;
	    
	}
};