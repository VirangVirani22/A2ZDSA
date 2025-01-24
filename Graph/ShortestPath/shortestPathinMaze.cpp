class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[8] = {-1,-1,0,1,1,1,0,-1};
        int dy[8] = {0,-1,-1,-1,0,1,1,1};
        if(grid[0][0]!=0) return -1;
        queue <pair<int,int> > q;
        q.push({0,0});
        vector <vector <int> > dis(n,vector <int> (m,1e9));
        dis[0][0]=0;
        while(!q.empty()){
            auto nd = q.front();
            if(nd.first==n-1 && nd.second==m-1) return dis[n-1][m-1]+1;
            q.pop();
            for(int i=0;i<8;i++){
                int x = nd.first + dx[i];
                int y = nd.second + dy[i];
                
                if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==0 && dis[x][y] > dis[nd.first][nd.second] + 1){
                    // cout<<x<<" "<<y<<endl;
                    dis[x][y] = dis[nd.first][nd.second]+1;
                    q.push({x,y});
                }
            }
            
        }
        if(dis[n-1][m-1]==1e9) return -1;
            return dis[n-1][m-1]+1;
    }
};