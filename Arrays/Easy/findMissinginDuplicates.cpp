//brute force : O(n^2)

//bater : using hashing

//optimal
class Solution{
public:	
	int search(int a[], int n){
	    //code
	    int xr = 0;
	    for(int i=0;i<n;i++){
	        xr = xr ^ a[i];
	    }
	    return xr;
	    
	}
	
};
