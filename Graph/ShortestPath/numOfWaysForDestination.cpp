class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector <vector <pair<long long,long long> > > adj(n);
        for(auto r:roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        vector <long long> dis(n,LONG_MAX),ways(n,0);
        priority_queue <pair <long long,long long> , vector < pair<long long,long long > >, 
        greater<pair<long long,long long> > >pq;
        pq.push({0,0});
        dis[0]  = 0 ;
        ways[0] = 1;
        while(!pq.empty()){
            long long d = pq.top().first;
            long long nd = pq.top().second;
            // cout<<nd<<" "<<d<<endl;
            pq.pop();
            
            for(auto e: adj[nd]){
                if(d + e.second < dis[e.first]){
                    dis[e.first] = d + e.second;
                    pq.push({dis[e.first],e.first});
                    ways[e.first] = ways[nd]% (long long)(1e9+7);
                }else if(d + e.second == dis[e.first]){
                    ways[e.first] = (ways[nd]% (long long)(1e9+7) + ways[e.first]% (long long)(1e9+7)) % (long long)(1e9+7);
                }
            }
        }
        return ways[n-1]% int(1e9+7);
    }
};