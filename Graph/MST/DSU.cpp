class DSU{
    vector <int> par,size,rank;
    public:
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