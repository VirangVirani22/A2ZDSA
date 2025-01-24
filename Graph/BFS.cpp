class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        queue<int> q;
        vector<int> ans;
        int  n = adj.size();
        vector<int> vis(n,0);
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto e:adj[x]){
                if(!vis[e]){
                    q.push(e);
                    vis[e]=1;
                }
            }
        }
        return ans;
    }
};