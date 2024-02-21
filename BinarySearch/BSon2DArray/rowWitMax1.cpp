
int lowerbound(vector<int> &a,int m){
    int l = 0, r = m-1, ans = -1;
    while(l<=r){
        int mid = l + (r-l) /2;
        if(a[mid]==1){
            ans= mid;
            r = mid -1;
        }else{
            l = mid + 1;
        }
       
    }
     return l;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.
    int ans = -1,cnt = INT_MIN;
    for(int i = 0;i<n;i++){
        int l = lowerbound(matrix[i],m);
        

        // if(ans!=-1)
    
        if(l<m && matrix[i][l]==1) {
            if((m-l)>cnt){
                ans = i;
                cnt = m - l;
            }
        }
       // cout<<l<<" "<<cnt<<" "<<ans<<endl;
    }
   
    return ans;
}