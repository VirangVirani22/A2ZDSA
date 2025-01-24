class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    void dfs(int i,int j,int n,int m, vector<vector<char>>& board,vector<vector<int>>& vis){
        vis[i][j] = 1;
        for(int k=0;k<4;k++){
            int x = i + dx[k];
            int y = j + dy[k];
            // cout<<x<<" "<<y<<endl;
            if(x>=0 & y>=0 && x<n && y<m && vis[x][y]==0 && board[i][j]=='O'){
               dfs(x,y,n,m,board,vis);
            }
        }
        
        
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector <vector <int> > vis(n,vector <int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0 && (i==0 || j==0 || i==n-1 || j==m-1))
                {
                    // cout<<i<<" "<<j<<endl;
                    dfs(i,j,n,m,board,vis);
                }
            }
        } 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0)
                board[i][j] = 'X';
            }
        }
        

    }
};