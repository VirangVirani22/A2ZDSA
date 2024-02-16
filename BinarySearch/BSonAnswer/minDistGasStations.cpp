//brute force O(k*n)
#include <bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.	
	

	int  n = arr.size();

	int cnts[n-1];
	for(int i=0;i<n-1;i++) cnts[i]  = 0;
	for(int j=1;j<=k;j++){
		// cout<<j<<endl;
		double mx = DBL_MIN;
		int ind  = -1;
		for(int i=0;i<n-1;i++){
			double res = ((double)arr[i+1] - arr[i])/(cnts[i]+1);
			if(res>mx){
				mx = res;
				ind = i;
			}
		}
	
		cnts[ind]++;
		// for(int i=0;i<n-1;i++) cout<<cnts[i]<<" ";
		// cout<<endl<<" "<<mx<<" "<<ind<<" "<<endl;

	}
	double ans = DBL_MIN;
	for(int i=0;i<n-1;i++){
		double tmp = ((double)(arr[i+1] - arr[i])/(cnts[i]+1));
		if(tmp>ans) ans = tmp;
	}
	return ans;
	


}

//using priority queue O(k*logn)
#include <bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.	
	

	int  n = arr.size();
	priority_queue < pair <double,int> >  pq;
	for(int i=0;i<n-1;i++){
		pq.push({(double)(arr[i+1]-arr[i]), i});
	}
	int cnts[n-1];
	for(int i=0;i<n-1;i++) cnts[i]  = 0;
	for(int j=1;j<=k;j++){
		// cout<<j<<endl;
		// double mx = DBL_MIN;
		// int ind  = -1;
		// for(int i=0;i<n-1;i++){
		// 	double res = ((double)arr[i+1] - arr[i])/(cnts[i]+1);
		// 	if(res>mx){
		// 		mx = res;
		// 		ind = i;
		// 	}
		// }
		
		double mx = pq.top().first;
		int ind = pq.top().second;
		pq.pop();



		cnts[ind]++;

		double temp = ((double)arr[ind+1] - arr[ind])/(cnts[ind]+1);
		pq.push({temp,ind}); 
		// for(int i=0;i<n-1;i++) cout<<cnts[i]<<" ";
		// cout<<endl<<" "<<mx<<" "<<ind<<" "<<endl;

	}
	double ans = DBL_MIN;
	for(int i=0;i<n-1;i++){
		double tmp = ((double)(arr[i+1] - arr[i])/(cnts[i]+1));
		if(tmp>ans) ans = tmp;
	}
	return ans;
	


}



//optimnal binary serach 
#include <bits/stdc++.h>
bool fun(double mid,vector<int> &arr, int k,int n){
	int cnt = 0;
	for(int i=0;i<n-1;i++){
		int tmp = (arr[i+1] - arr[i])/mid;
		if((arr[i+1]-arr[i])==tmp*mid) tmp--;
		
		cnt+=tmp;
	}
	// cout<<mid<<" "<<cnt<<endl;
	if(cnt<=k) return true;
	return false;
}
double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.	
	

	int  n = arr.size();
	double l =0.0, r = DBL_MIN;
	for(int i=0;i<n-1;i++){
		r = max(r,(double)(arr[i+1] - arr[i]));
	}
	double ans = r;
	// cout<<l<<" "<<r<<endl;
	while(r-l>1e-6){
		double mid = l + (r-l)/(double)2;
		// cout<<mid<<endl;
		if(fun(mid,arr,k,n)){
			ans = mid;
			r = mid;
		}else{
			l = mid;
		}
	}
	return ans;
	


}
/*
1 2 3 4 5
0.6 3
*/
