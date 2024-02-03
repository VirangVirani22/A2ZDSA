//1
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int l = 0 , r = n -1, first = -1, last = -1 ;
    while(l<=r){
        int mid = l + (r-l) / 2;
        if(arr[mid]==k){
            first = mid;
            r  = mid - 1;
        }else if(arr[mid]>k){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    l = 0 , r = n -1 ;
    while(l<=r){
        int mid = l + (r-l) / 2;
        if(arr[mid]==k){
            last = mid;
            l = mid + 1;
        }else if(arr[mid]>k){
            r = mid  -1 ;
        }else{
            l = mid + 1;
        }
    }
    return make_pair(first,last);
}
//#include<bits/stdc++.h>
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
   int lb = lower_bound(arr.begin(),arr.end(),k) - arr.begin();
   int up = upper_bound(arr.begin(),arr.end(),k) - arr.begin();
   if(lb!=n && arr[lb]==k) return make_pair(lb,up-1);
   else make_pair(-1,-1);
}
//find number of occurrences
#include<bits/stdc++.h>
int count(vector<int>& arr, int n, int k) {
	int lb = lower_bound(arr.begin(),arr.end(),k) - arr.begin();
   int up = upper_bound(arr.begin(),arr.end(),k) - arr.begin();
   if(lb!=n && arr[lb]==k) return up-lb;
   else return 0;
}


