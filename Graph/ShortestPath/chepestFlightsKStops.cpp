class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector <vector <pair<int,int> > > adj(n);
        for(auto f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        vector <int> dis(n,INT_MAX), cnt(n,0);
        queue <pair<int,pair<int,int>> > pq;
        pq.push({0,{src,0}});
        dis[src] = 0;

        while(!pq.empty()){
            int nd = pq.front().second.first;
            int c = pq.front().second.second;
            int d = pq.front().first;
            // cout<<nd<<" "<<d<<" "<<c<<endl;
            pq.pop();
            
            
            if(c>k) continue;
            for(auto e:adj[nd]){
                if(d + e.second < dis[e.first]){
                    dis[e.first] = d + e.second;
                    pq.push({dis[e.first],{e.first,c+1}});
                }
            }
        }
        return dis[dst]==INT_MAX?-1:dis[dst];

    }
};

//here we cant use priority queue for distance
//queue will ensure that we are going by count ie. first all 1 stopts , then all 2 stopts