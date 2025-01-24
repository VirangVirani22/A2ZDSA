class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        queue <int > q;
        int n = adj.size();
        vector <int> dis(n,-1);
        q.push(src);
        int lev = 1;
        dis[src] = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int e = q.front();
                q.pop();
                for(auto nd: adj[e]){
                    if(dis[nd]==-1){
                        dis[nd] = lev;
                        q.push(nd);
                    }
                    
                }
            }
            lev++;
            
        }
        return dis;
    }
};

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        queue <int > q;
        int n = adj.size();
        vector <int> dis(n,INT_MAX);
        dis[src] = 0;
        q.push(src);
        while(!q.empty()){
            int e = q.front();
            q.pop();
            for(auto nd: adj[e]){
                if(dis[e]+1<dis[nd]){
                    dis[nd] = dis[e]+ 1;
                    q.push(nd);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dis[i]==INT_MAX) dis[i] = -1;
        }
        return dis;
    }
};