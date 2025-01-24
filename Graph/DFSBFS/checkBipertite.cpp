class Solution {
public:
    bool isB(int nd,vector<vector<int>>& graph, vector<int> &vis,int col){
        vis[nd] = col;
        for(auto x: graph[nd]){
            if(vis[x]==-1){
                if(!isB(x,graph,vis,1-col)) return false;
            }else if(col==vis[x]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!isB(i,graph,vis,0)) return false;
            }
        }
        return true;
    }
};