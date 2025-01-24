class Solution {
  public:
    string findOrder(vector<string> dict, int k) {
        // code here
        int n = dict.size();
        vector <int> in(k,0);
        vector <vector <int> > adj(k);
        for(int i=0;i<n-1;i++){
            int l = min(dict[i].length(),dict[i+1].length());
            for(int j=0;j<l;j++){
                if(dict[i][j]!=dict[i+1][j]){
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    in[dict[i+1][j]-'a']++;
                    break;
                }
            }
        }
        queue <int> q;
        for(int i=0;i<k;i++){
            if(in[i]==0) q.push(i);
        }
        string ans="";
        while(!q.empty()){
            int node = q.front();
            ans+=(char(node+'a'));
            q.pop();
            for(auto it: adj[node]){
                in[it]--;
                if(in[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
      
    }
};