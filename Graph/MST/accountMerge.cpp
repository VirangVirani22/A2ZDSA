class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map <string,int> mailmap;
        int n = accounts.size();
        DSU dsu(n);
        for(int i=0;i<n;i++){
            string name = accounts[i][0];
            for(int j=1;j<accounts[i].size();j++){
                if(mailmap.find(accounts[i][j])==mailmap.end()){
                    mailmap[accounts[i][j]] = i;
                }else{
                    cout<<accounts[i][j]<<endl;
                    dsu.unionBySize(i,mailmap[accounts[i][j]]);
                }
            }
            
        }
        vector <string> lst[n];
        for(auto m:mailmap){
            string email = m.first;
            int group = dsu.findPar(m.second);
            cout<<email<<" "<<group<<endl;
            lst[group].push_back(email);
        }
        vector <vector <string> > ans;
        for(int i=0;i<n;i++){
            if(lst[i].size()==0) continue;
            sort(lst[i].begin(),lst[i].end());
            vector <string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : lst[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;

    }
};