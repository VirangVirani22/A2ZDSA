class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        int sum = 0;
        priority_queue < pair<int,int> , 
        vector < pair<int,int> >  , 
        greater< pair<int,int> >  > pq;
        
        vector <int> vis(V,0);
        
        pq.push({0,0});
        while(!pq.empty()){
            auto e = pq.top();
            pq.pop();
            int d = e.first;
            int nd = e.second;
            if(vis[nd]) continue;
            vis[nd ] = 1;
            sum+=d;
            for(auto edge:adj[nd]){
                if(!vis[edge[0]]){
                    pq.push({edge[1],edge[0]});
                }
            }
            
        }
        return sum;
    
        
    }
    
};