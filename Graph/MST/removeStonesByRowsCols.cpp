class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxx=0,maxy=0;
        set<int> uq;
        for(auto s:stones){
            maxx=max(maxx,s[0]);
            maxy=max(maxy,s[1]);
            
        }
        DSU dsu(maxx+maxy+2);
        
        for(auto s:stones){
            dsu.unionBySize(s[0],s[1]+maxx+1);
            uq.insert(s[0]);
            uq.insert(s[1]+maxx+1);

        }
        int cnt = 0;
        for(auto it: uq){
            // cout<<it<<" "<<dsu.findPar(it)<<endl;
            if(dsu.findPar(it)==it) cnt++;
        }
        return stones.size() - cnt;
    }
};