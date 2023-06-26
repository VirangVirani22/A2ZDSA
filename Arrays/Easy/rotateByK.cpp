//left rotate array by k position

//brute-force usning o(k) space complexity


class Solution{
	
	
	public:
	void leftRotate(int arr[], int k, int n) 
	{ 
	   // Your code goes here
	   k = k%n;
	   int temp[k];
	   for(int i=0;i<k;i++) temp[i] = arr[i];
	   for(int i=k;i<n;i++){
	       arr[i-k] = arr[i];
	   }
	   for(int i=n-k;i<n;i++){
	       arr[i] = temp[i-(n-k)];
	   }
	   
	} 
		 


};

//optimized by observation

class Solution{
	
	
	public:
	void leftRotate(int arr[], int k, int n) 
	{ 
	   // Your code goes here
	   k = k%n;
	   reverse(arr,arr+k);
	   reverse(arr+k,arr+n);
	   reverse(arr,arr+n);
	   
	} 
		 


};