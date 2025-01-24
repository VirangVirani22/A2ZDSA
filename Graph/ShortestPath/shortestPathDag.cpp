class Solution {
  public:
  void topo(int node, vector <vector <pair<int,int> > > &adj, vector <int> &vis, stack<int> &st){
      vis[node] = 1;
      for(auto it:adj[node]){
          if(!vis[it.first]){
              topo(it.first,adj,vis,st);
          }
      }
      st.push(node);
  }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        vector <int> vis(V,0);
        vector <vector <pair<int,int> > > adj(V);
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
        stack<int>  st;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                topo(i,adj,vis,st);
            }
        }
        vector <int> dis(V,INT_MAX);
        dis[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it:adj[node]){
                int d = it.second;
                int n = it.first;
                if(dis[node]!=INT_MAX && dis[n]>d+dis[node]){
                    dis[n] = d + dis[node];
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dis[i]==INT_MAX) dis[i] = -1;
        }
        return dis;
    }
};