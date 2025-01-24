class Solution {
    int timer = 0;
    void dfs(int node,int par,vector<int> adj[], vector<int> &vis, vector<int> &in, vector<int> &low, vector<int> &isAp){
        vis[node] = 1;
        in[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto it:adj[node]){
            if(it==par) continue;
            if(vis[it]==0){
                child++;
                dfs(it,node,adj,vis,in,low,isAp);
                low[node] = min(low[node],low[it]);
                if(low[it]>=in[node] && par!=-1){
                    isAp[node] = 1;
                }
            }else{
                low[node] = min(low[node],in[it]);
            }
        }
        if(par==-1 && child>1){
            isAp[node] = 1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector <int> in(V,0),low(V,0),vis(V,0),isAp(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,-1,adj,vis,in,low,isAp);
            }
        }
        vector <int> ans;
        for(int i=0;i<V;i++){
            if(isAp[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.empty()) return {-1};
        return ans;
        
        
    }
};