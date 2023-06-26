//move all zeros to the end

//brute-force : using set (extra space)

//optimized two pointers

class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    
	    int zind = -1;
	    for(int i=0;i<n;i++){
	        if(arr[i]==0){
	            zind = i;
	            break;
	        }
	    }
	    if(zind==-1) return;
	    for(int i=zind+1;i<n;i++){
	        if(arr[i]!=0){
	            swap(arr[zind],arr[i]);
	            zind++;
	        }
	    }
	    
	}
};