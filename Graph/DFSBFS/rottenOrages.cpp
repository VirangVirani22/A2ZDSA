class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue <pair<int,int> > q;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});

                }else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        
        int minute = 0;
        while(!q.empty()){
            int sz = q.size();
            for (int s=0;s<sz;s++){
                auto e = q.front();
                // cout<<e.first<<" "<<e.second<<endl;
                q.pop();
                for(int i=0;i<4;i++){
                    int x = e.first + dx[i];
                    int y = e.second + dy[i];

                    if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1){
                        // cout<<"in"<<endl;
                        // cout<<x<<" "<<y<<endl;
                        grid[x][y] = 2;
                        q.push({x,y});
                        cnt--;
                    }
                }
            }
            minute++;
        }
        cout<<cnt<<" "<<minute;
        if(cnt!=0) return -1;
        if(minute<=0) return 0;
        return minute-1;
    }
};