class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector <int> dis(V,1e8);
        int e = edges.size();
        dis[src] = 0;
        for(int i=0;i<V-1;i++){
            for(auto e:edges){
                if(dis[e[0]]!=1e8 && dis[e[0]]+ e[2] < dis[e[1]]){
                    dis[e[1]] = dis[e[0]]+ e[2] ;
                }
            }
        }
        
        for(auto e:edges){
                if(dis[e[0]]!=1e8 && dis[e[0]]+ e[2] < dis[e[1]]) return {-1};
        }
        
        return dis;
    
    }
};