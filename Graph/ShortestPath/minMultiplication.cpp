class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue <pair<int,int> > q;
        int n = arr.size();
        vector <int> dis(100000,100001);
        
        // cout<<dis[0]<<" "<<dis[1]<<endl;
        q.push({start,0});
        dis[start] = 0;
        while(!q.empty()){
            int num = q.front().first;
            int d = q.front().second;
            // cout<<num<<" "<<d<<endl;
            if(num==end) return d;
            q.pop();
            for(int i=0;i<n;i++){
               int x = (num * arr[i] ) % 100000;
            //   cout<<x<<endl;
               if(dis[x]>d+1){
                   dis[x]  = d + 1;
                   q.push({x,d+1});
               }
            }
        }
        return -1;
    }
};