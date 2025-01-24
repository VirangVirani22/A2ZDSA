class Solution {
    void dfs1(int node,vector <int> &vis,stack <int> &st, vector<vector<int>> &adj){
        vis[node] = 1;
        // cout<<node<<endl;
        for(auto it:adj[node]){
            if(vis[it]==0){
                // cout<<" "<<it<<endl;
                dfs1(it,vis,st,adj);
            }
        }
        st.push(node);
    }
  
   void reverse(vector<vector<int>> &adj,vector<vector<int>> &radj,vector <int> &vis,int n){
       
       for(int i=0;i<n;i++){
            vis[i] = 0;
           for(auto it:adj[i]){
               radj[it].push_back(i);
           }
       }
   }
   void dfs2(int node,vector <int> &vis, vector<vector<int>> &radj){
        vis[node] = 1;
        for(auto it:radj[node]){
            if(vis[it]==0)
                dfs2(it,vis,radj);
        }
        
    }
   public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        
        int n = adj.size();
        stack <int> st;
    //     for(int i=0;i<n;i++){
    //         cout<<i<<"  --->";
    //       for(auto it:adj[i]){
    //           cout<<it<<" ";
    //       }
    //       cout<<endl;
    //   }
    //   cout<<endl;
        vector <int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs1(i,vis,st,adj);
        }
        
        vector<vector<int>> radj(n);
        reverse(adj,radj,vis,n);
        int cnt = 0;
        // cout<<"stack"<<endl;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            // cout<<node<<endl;
            if(!vis[node]){
                cnt++;
                dfs2(node,vis,radj);
            }
        }
        return cnt;
    }
};