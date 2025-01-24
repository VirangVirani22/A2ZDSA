class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void dfs(int nd,vector<vector<int>>& adj, vector <int> &vis, stack <int> &st){
        vis[nd] = 1;
        for(auto e: adj[nd]){
            if(!vis[e]) dfs(e,adj,vis,st);
        }
        st.push(nd);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int n = adj.size();
        vector <int> vis(n,0);
        stack <int> st;
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,adj,vis,st);
        }
        vector <int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};