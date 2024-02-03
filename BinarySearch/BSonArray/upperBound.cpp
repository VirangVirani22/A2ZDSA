//1
int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	
	int l=0, r = n-1, ans = n;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(arr[mid]<=x) l = mid + 1;
		else r = mid - 1, ans = mid;
	}
	return ans;
}
//without using ans var
int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	
	int l=0, r = n-1;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(arr[mid]<=x) l = mid + 1;
		else r = mid - 1;
	}
	return r +1;
}