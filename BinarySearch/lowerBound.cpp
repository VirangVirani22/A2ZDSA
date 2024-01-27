//1
int lowerBound(vector<int> arr, int n, int x) {
	int l = 0 , r =n-1;
	int ans = n;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(arr[mid]>=x) r = mid -1, ans = mid;
		else l =mid + 1;
	}
	return ans; 
}
//without ans var
int lowerBound(vector<int> arr, int n, int x) {
	int l = 0 , r =n-1;
	// int ans = n;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(arr[mid]>=x) r = mid -1;
		else l =mid + 1;
	}
	return r+1; 
}

