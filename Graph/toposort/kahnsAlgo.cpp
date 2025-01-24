class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int n = adj.size();
        vector <int> in(n,0);
        vector <int> ans;
        for(auto e: adj){
            for(auto nd: e){
                in[nd]++;
            }
        }
        queue <int> q;
        for(int i=0;i<n;i++) {
            if(in[i]==0) {
                q.push(i);
            }
        }
        while(!q.empty()){
            int nd = q.front();
            q.pop();
            ans.push_back(nd);
            for(auto e:adj[nd]){
                in[e]--;
                if(in[e]==0){
                    q.push(e);
                }
            }
        }
        return ans;
    }
};