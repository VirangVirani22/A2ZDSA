class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue < pair<int,int> > q;
        vector <vector<int> > vis(n,vector<int> (m,0));
        q.push({sr,sc});
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        int og = image[sr][sc];
        image[sr][sc] = color;
        vis[sr][sc] = 1;
        while(!q.empty()){
            auto e = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x = e.first + dx[i];
                int y = e.second + dy[i];
                if(x>=0 && y>=0 && x<n && y<m && image[x][y]==og && vis[x][y]==0){
                    image[x][y] = color;
                    vis[x][y] = 1;
                    q.push({x,y});
                }
            }
        }
        return image;
    }
};