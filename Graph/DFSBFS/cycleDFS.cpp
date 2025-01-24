class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkcycle(int nd,int par, vector< vector<int> >& adj, int n, vector <int> &vis){
        vis[nd] = 1;
        for(auto x:adj[nd]){
            if(vis[x]==0){
                if(checkcycle(x,nd,adj,n,vis)) return true;
                
            }else if(x!=par) 
                return true;
        }
        return false;
    }
    bool isCycle(vector< vector<int> >& adj) {
        // Code here
        int n  = adj.size();
        vector <int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                 if(checkcycle(i,-1,adj,n,vis)) return true;
            }
        }
        return false;
    }
};