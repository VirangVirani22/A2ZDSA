class Solution {
public:
    void dfs(int nd,vector<vector<int>>& mat,vector<int> &vis, int n){
        // cout<<nd<<endl;
        vis[nd]=1;
        for(int i=0;i<n;i++){
            if(mat[nd][i]==1 && !vis[i]){
                dfs(i,mat,vis,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        int cnt = 0;
        vector<int> vis(n,0);

        for(int i=0;i<n;i++){
           
                vis[i]=0;
          
        }
        for(int i=0;i<n;i++){
            
                if(!vis[i]){
                    cnt++;
                    dfs(i,mat,vis,n);
                }
            
        }
        return cnt;
       
    }
};