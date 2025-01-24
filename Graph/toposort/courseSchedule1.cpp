vector <int> in(n,0);
        vector <vector <int> > adj(n);
        for(auto p:pres){
            adj[p[0]].push_back(p[1]);
            in[p[1]]++;
        }
        queue<int> q;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int nd = q.front();
            cnt++;
            q.pop();
            for(auto e:adj[nd]){
                in[e]--;
                if(in[e]==0){
                    q.push(e);
                }
            }
        }

        return n==cnt?true:false;