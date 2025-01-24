class DSU{
     public:
    vector <int> par,size,rank;
   
    DSU(int n){
        par.resize(n);
        size.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            size[i] = 1;
            par[i] = i;
            rank[i] = 0;
        }
    }
    
    int findPar(int n){
        if(par[n]==n) return n;
        return par[n] = findPar(par[n]);
    }
    
    void unionBySize(int x, int y){
        int a = findPar(x);
        int b = findPar(y);
        if(a==b) return;
        if(size[b]>size[a]){
            par[a] = b;
            size[b]+=size[a]; 
        }else{
            par[b] = a;
            size[a] += size[b];
        }
    }
    
    void unioByRank(int x,int y){
        int a = findPar(x);
        int b = findPar(y);
        if(a==b) return;
        if(rank[a]>rank[b]){
            par[b] = a;
        }else if(rank[b]>rank[a]){
            par[a] = b;
        }else{
            par[b] = a;
            rank[a]++;
        }
    }
};
class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(int a=0;a<4;a++){
                        int newRow = i + dx[a];
                        int newCol = j + dy[a];
                        if(newRow>=0 && newCol>=0 && newRow<n && newCol<n && grid[newRow][newCol]==1){
                            int cur = i*n + j;
                            int newCur = newRow*n + newCol;
                            dsu.unionBySize(cur,newCur);
                        } 
                    }
                }
            }
        }
        int mx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int sum = 0;
                    set<int> groups;
                    for(int a=0;a<4;a++){
                        int newRow = i + dx[a];
                        int newCol = j + dy[a];
                        if(newRow>=0 && newCol>=0 && newRow<n && newCol<n){
                            int cur = i*n + j;
                            int newcur = newRow*n + newCol;
                            if(grid[newRow][newCol]==1)
                                groups.insert(dsu.findPar(newcur));
                        } 
                    }
                    sum++;
                    for(auto s:groups){
                        sum+=dsu.size[s];
                    }
                   mx = max(sum,mx);
                }
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            // cout<<cellNo<<" "<<dsu.findPar(cellNo)<<" "<<dsu.size[dsu.findPar(cellNo)]<<endl;
            mx = max(mx, dsu.size[dsu.findPar(cellNo)]);
        }
        return mx;
        
    }
};