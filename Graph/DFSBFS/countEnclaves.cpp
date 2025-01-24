class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    void dfs(int a,int b,int n, int m,vector<vector<int>>& grid, vector<vector<int>>& vis,int &cnt){
        vis[a][b] = 1;
        cnt--;
        // cout<<a<<" "<<endl;
        for(int i=0;i<4;i++){
            int x = a + dx[i];
            int y = b + dy[i];
            if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==0 && grid[x][y]==1){
                dfs(x,y,n,m,grid,vis,cnt);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector <vector<int> > vis(n,vector <int> (m,0));

        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt++;
                }
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0 && (i==0 || j==0 || i==n-1 || j==m-1) ){
                   dfs(i,j,n,m,grid,vis,cnt);
                }
                
            }
        }
        return cnt;
    }
};