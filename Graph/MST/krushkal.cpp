class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector <pair < int, pair<int,int> > > edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                edges.push_back({it[1],{i,it[0]}});
            }
        }
        sort(edges.begin(),edges.end());
        int sum = 0;
        DSU dsu(V);
        for(auto e:edges){
            int wt = e.first;
            int a = e.second.first;
            int b = e.second.second;
            int parA = dsu.findPar(a);
            int parB = dsu.findPar(b);
            if(parA!=parB){
                dsu.unionBySize(parA,parB);
                sum+=wt;
            }
        }
        return sum;
    }
};