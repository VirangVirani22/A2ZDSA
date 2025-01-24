class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pres) {
        vector <int> in(n,0);
        vector <vector <int> > adj(n);
        for(auto p:pres){
            adj[p[1]].push_back(p[0]);
            in[p[0]]++;
        }
        queue<int> q;
        vector <int> ans;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int nd = q.front();
            ans.push_back(nd);
            q.pop();
            for(auto e:adj[nd]){
                in[e]--;
                if(in[e]==0){
                    q.push(e);
                }
            }
        }

        if(ans.size()==n) return ans;
        ans.clear();
        return ans;
    }
};