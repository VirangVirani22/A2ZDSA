//bruteforce : without sorting complex 
//optimal :
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& vals) {
         // Code here
         sort(vals.begin(),vals.end( ));
         vector <vector<int>> ans;
         int n = vals.size( );
         for( int i=0;i<n;i++){
             if(ans.empty( ) || vals[i][0]>ans.back()[1]){
                 ans.push_back(vals[i]);
             }else{
                 ans.back( )[1] = max(ans.back( )[1], vals[i][1]);
             }
         }
         return ans;
    }
};