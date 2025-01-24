class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isC(int nd, vector<vector<int>> &adj, vector<int> &vis, vector <int> &cur){
        // cout<<nd<<endl;
        vis[nd] =1;
        cur[nd] =1;
        for(auto x:adj[nd]){
            if(!vis[x]){
                if(isC(x,adj,vis,cur)) return true;
            }else if(cur[x]){
                return true;
            }
        }
        cur[nd] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        // for(auto a:adj){
        //     for(auto b:a){
        //         cout<<b<<" ";
        //     }
        //     cout<<endl;
        // }
        
        
        vector <int> vis(V,0),cur(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isC(i,adj,vis,cur)) return true;
            }
        }
        return false;
    }
};