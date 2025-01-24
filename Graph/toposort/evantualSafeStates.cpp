class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n =graph.size();
        vector<vector<int>> adj(n);
        vector <int> in(n,0);
        for(int i=0;i<n;i++){
            for(auto e:graph[i]){
                adj[e].push_back(i);
                in[i]++;
            }
            
        }
        
        queue <int> q;
        for(int i=0;i<n;i++){
            if(!in[i]) q.push(i);
        }
        vector <int> ans;
        while(!q.empty()){
            int nd = q.front();
            q.pop();
            ans.push_back(nd);
            for(auto e:adj[nd]){
                in[e]--;
                if(in[e]==0) q.push(e);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};