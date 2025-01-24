class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n = adj.size();
        vector <int> dis(n,INT_MAX);
        priority_queue <pair <int,int> , vector < pair<int,int > >, 
        greater<pair<int,int> > >pq;
        pq.push({0,src});
        dis[src]  = 0 ;
        while(!pq.empty()){
            int d = pq.top().first;
            int nd = pq.top().second;
            // cout<<nd<<" "<<d<<endl;
            pq.pop();
            
            for(auto e: adj[nd]){
                if(d + e.second < dis[e.first]){
                    dis[e.first] = d + e.second;
                    pq.push({dis[e.first],e.first});
                }
            }
        }
        return dis;
    }
};