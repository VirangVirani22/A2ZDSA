lass Solution {
  public:
  int dx[4] = {-1,0,1,0};
  int dy[4] = {0,1,0,-1};
    void dfs(int a,int b, int n ,int m, vector<vector<int>>& grid, vector<vector<int>>& vis,
    int sa,int sb, vector <pair <int,int> > &graph){
        vis[a][b] = 1;
        graph.push_back({a-sa,b-sb});
        for(int i=0;i<4;i++){
            int x = a + dx[i];
            int y = b + dy[i];
            if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1 && vis[x][y]==0){
                dfs(x,y,n,m,grid,vis,sa,sb,graph);
            }
        }
        
        
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector <vector <int> > vis(n,vector <int> (m,0));
        set <vector <pair<int,int> > >st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(vis[i][j]==0 && grid[i][j]==1){
                    vector < pair<int,int>> graph;
                    dfs(i,j,n,m,grid,vis,i,j,graph);
                    st.insert(graph);
                    cnt++;
                }
            }
        }
        return st.size();
    }
};