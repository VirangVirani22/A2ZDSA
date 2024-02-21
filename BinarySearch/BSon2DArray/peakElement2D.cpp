class Solution {
    int findmax(int mid,vector<vector<int>>& mat,int n,int m){
        int mx = INT_MIN,ind=-1;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>mx){
                mx = mat[i][mid];
                ind = i;
            }
        }
        return ind;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0, r = m -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int mx  = findmax(mid,mat,n,m);
            int left  = -1, right = -1;
            if(mid>0) left = mat[mx][mid-1];
            if(mid<m-1) right = mat[mx][mid+1];
            if(left<mat[mx][mid] && right<mat[mx][mid]){
                vector <int> ans = {mx,mid};
                return ans;
            }else if(left>mat[mx][mid]){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        vector <int> ans;
        return ans;
    }
};