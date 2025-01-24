
class Solution {
    void dfs(int nd,vector<int> &vis,vector<vector<int>>& adj,vector<int> &ans){
        vis[nd]=1;
        ans.push_back(nd);
        for(auto e:adj[nd]){
            if(!vis[e]){
                dfs(e,vis,adj,ans);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ans,vis(n,0);
        dfs(0,vis,adj,ans);
        return ans;
    }
    
};