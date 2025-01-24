class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};

        priority_queue < pair<int,pair<int,int> > , vector < pair<int,pair<int,int> > > ,
           greater< pair<int,pair<int,int> > > > pq;
        pq.push({0,{0,0}});

        vector <vector <int> > dis(n,vector <int> (m,INT_MAX));
        dis[0][0] = 0;
        while(!pq.empty()){
            int d = pq.top().first;
            int a = pq.top().second.first;
            int b = pq.top().second.second;
            pq.pop();
            // cout<<a<<" "<<b<<" "<<d<<endl;
            if(a==n-1 && b==m-1){
                return d;
            }
            for(int i=0;i<4;i++){
                int x = a + dx[i];
                int y = b + dy[i];
                if(x>=0 && y>=0 && x<n && y<m) {
                    int eff = max(abs(heights[x][y]-heights[a][b]),d);
                    // cout<<x<<" "<<y<<" "<<eff<<endl;
                    if(eff<dis[x][y]){
                        dis[x][y] = max(abs(heights[x][y]-heights[a][b]),d);
                         pq.push({dis[x][y],{x,y}});
                    }
                    
                }
            }
        }
        return -1;
    }
};