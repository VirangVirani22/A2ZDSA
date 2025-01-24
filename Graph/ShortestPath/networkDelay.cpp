class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector <vector <pair<int,int> > > adj(n);
        for(auto t:times){
            adj[t[0]-1].push_back({t[1]-1,t[2]});
        }
        vector <int> dis(n,INT_MAX);
        priority_queue <pair <int,int> , vector < pair<int,int > >, 
        greater<pair<int,int> > >pq;
        pq.push({0,src-1});
        dis[src-1]  = 0 ;
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
        int mx = -1;
        for(auto e: dis){
            if(e==INT_MAX) return -1;
            mx = max(e,mx);
        }
        return mx;
        
    }
};