class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        vector <int> dis(n,INT_MAX);
        
        set <pair<int,int> > st;
        st.insert({0,src});
        dis[src]  = 0 ;
        while(!st.empty()){
            auto i= *(st.begin());
            st.erase(i);
            int d = i.first;
            int nd = i.second;
            
            
            for(auto e: adj[nd]){
                if(d + e.second < dis[e.first]){
                    if(dis[nd]!=INT_MAX) 
                        st.erase({dis[e.first],e.first});
                    dis[e.first] = d + e.second;
                    st.insert({dis[e.first],e.first});
                }
            }
        }
        return dis;
    }
};