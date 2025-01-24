class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int T) {
        vector <vector <int> > mat(n,vector <int> (n,1e8));
        for(auto e:edges){
            mat[e[0]][e[1]] = e[2];
            mat[e[1]][e[0]] = e[2];
        }

        for(int i=0;i<n;i++){
           mat[i][i] = 0;;
        }
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j] = min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }

        // for(auto x:mat){
        //     for(auto y:x) cout<<y<<" ";
        //     cout<<endl;
        // }
        cout<<endl;
        int mincnt = n;
        int ans  = -1;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(j!=i && mat[i][j]<=T){
                    cnt++;
                }
            }
            
            if(cnt<=mincnt){
                mincnt = cnt;
                ans = i;
            }
            // cout<<i<<" "<<cnt<<" "<<mxcnt<<" "<<ans<<endl;
        }
        return ans;
    }
};