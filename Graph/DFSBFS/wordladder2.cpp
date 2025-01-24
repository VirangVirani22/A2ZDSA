class Solution {
public:
    vector<vector<string>> findSequences(string beginw, string endw, vector<string>& wordList) {
         unordered_set <string> st(wordList.begin(),wordList.end());
        queue<vector <string> > q;
        vector <string> usedinlevel;
        int level = 0;
        vector <string> x;
        x.push_back(beginw);
        q.push(x);
        usedinlevel.push_back(beginw);
        vector <vector <string> > ans;
        while(!q.empty()){
            auto path = q.front();
            // for(auto p:path) cout<<p<<" "; cout<<endl;
            q.pop();
            string cur = path.back();
            int n = cur.size();
            if(cur==endw){
                if(ans.size()==0) ans.push_back(path);
                else if(ans[0].size()==path.size()) ans.push_back(path);
            }
            if(path.size()>level){
                for(auto e: usedinlevel){
                    st.erase(e);
                }
                usedinlevel.clear();
                level++;
            }
            
            for(int i=0;i<=n;i++){
                char og = cur[i];
                for(char c='a';c<='z';c++){
                    cur[i] = c;
                    if(st.count(cur)>0){
                        usedinlevel.push_back(cur);
                        path.push_back(cur);
                        q.push(path);
                        path.pop_back();
                    }
                }
                cur[i] = og;
            }
        }
        return ans;
    }
};