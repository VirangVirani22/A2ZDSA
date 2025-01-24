class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector <pair <int,int> > edges;
        for(auto c: connections){
            edges.push_back({c[0],c[1]});
        }
        int extra = 0;
        DSU dsu(n);
        for(auto e: edges){
            int a = e.first;
            int b = e.second;
            int parA = dsu.findPar(a);
            int parB = dsu.findPar(b);
            if(parA!=parB){
                dsu.unionBySize(parA,parB);
            }else{
                extra++;
            }
        }
        int cnt = -1;
        for(int i=0;i<n;i++){
            if(dsu.findPar(i)==i){
                cnt++;
            }
        }
        if(extra>=cnt) return cnt;
        return -1;
    }
};