class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<int> in(V,0);
        for(auto e:adj){
            for(auto nds: e){
                in[nds]++;
            }
        }
        queue <int> q;
        for(int i=0;i<V;i++){
            if(in[i]==0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int nd = q.front();
            q.pop();
            cnt++;
            for(auto e:adj[nd]){
                in[e]--;
                if(in[e]==0) q.push(e);
            }
        }
        return V==cnt?0:1;
    }
};