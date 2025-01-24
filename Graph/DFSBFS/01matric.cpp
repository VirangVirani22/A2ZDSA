class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int  n = mat.size();
        int m = mat[0].size();
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};
        vector < vector <int> > ans(n, vector <int> (m,0));
        queue < pair <pair <int,int>, int > > q;
        vector <vector <int>  > vis(n,vector <int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
      
        
        while(!q.empty()){
            int sz = q.size();
            for(int s=0; s<sz; s++){
                auto e = q.front();
                q.pop();
                // cout<<e.first.first<<" "<<e.first.second<<" "<<e.second<<endl;
                for(int i=0;i<4;i++){
                    int x = e.first.first + dx[i];
                    int y = e.first.second + dy[i];
                    // cout<<x<<" "<<y<<endl;
                    if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==0){
                        // cout<<x<<" "<<y<<endl;
                        
                            q.push({{x,y},e.second+1});
                            vis[x][y] = 1;
                            ans[x][y] = e.second+1;
                       
                    }
                }
            }
        }
        return ans;

    }
};