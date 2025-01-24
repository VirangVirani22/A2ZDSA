class Solution {
public:
    void dfs(int node,int par,vector <int> &vis,vector <vector <int> > &adj,vector <vector<int> > &ans, int timer,vector <int> &in,vector <int> &lowin ){
        vis[node] = 1;
        in[node] = lowin[node] = timer;
        timer++;
        for(auto it: adj[node]){
            if(it==par) continue;
            if(vis[it]==0){
                dfs(it,node,vis,adj,ans,timer,in,lowin);
                lowin[node] = min(lowin[node],lowin[it]);
                if(lowin[it]>in[node]){
                    vector <int> tmp;
                    tmp.push_back(node);
                    tmp.push_back(it);
                    ans.push_back(tmp);
                }
            }else{
                lowin[node] = min(lowin[node],lowin[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        vector <vector<int> > ans;
        vector <vector <int> > adj(n);

        for(auto c:conn){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        vector <int> vis(n,0);
        vector <int> in(n,0);
        vector <int> lowin(n,0);
        int timer = 0;
        dfs(0,-1,vis,adj,ans,timer,in,lowin);
        return ans;
    }
};