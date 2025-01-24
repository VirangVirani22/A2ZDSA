class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkcycle(int nd, vector< vector<int> >& adj, int n,vector <int> &vis){
        vis[nd] = 1; 
        queue<pair<int,int > > q;
        q.push({nd,-1});
        while(!q.empty()){
            auto e = q.front();
            q.pop();
            for(auto x:  adj[e.first]){
                if(vis[x]==0) {
                    q.push({x,e.first});
                    vis[x] = 1;
                }else if(x != e.second){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(vector< vector<int> >& adj) {
        // Code here
        int n  = adj.size();
        vector <int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                 if(checkcycle(i,adj,n,vis)) return true;
            }
        }
        return false;
    }
};