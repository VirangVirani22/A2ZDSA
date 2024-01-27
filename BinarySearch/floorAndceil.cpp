pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	pair <int,int> ans = {0,0};
	//floor
	int l = 0, r = n -1, floor = -1,ceil = -1 ;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(a[mid]<=x) {
			floor = a[mid];
			l = mid + 1;
		}
		else r = mid -1;
		
	}
	ans.first = floor;
	l = 0 , r = n -1 ; 
	while(l<=r){
		int mid = l + (r-l)/2;
		if(a[mid]>=x){
			r = mid - 1;
			ceil = a[mid];
		}
		else l = mid + 1;
	}
	ans.second = ceil;
	
	return ans;
	
	
}