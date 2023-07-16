//bruteforce : O(N^3*longN) longN for uniquesness using set
//better : using hashing O(N^2*LongN)
# include <bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &nums)
{
    set<vector <int> > ans;
    for( int i=0;i<n;i++){
        map <int,int> mp;
        for(int j=i+1;j<n;j++){
            int target  = -(nums[i]+nums[j]);
            if(mp.find(target)!=mp.end()){
                
                vector <int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(target);
                sort( temp.begin( ),temp.end( ));
                ans.insert( temp);
            }
            mp[nums[j]] = 1;
        }
    }
    vector <vector<int> > res(ans.begin() ,ans.end());
    return res;
    
}

//optimal : sorting and then two pointer in second loop
# include <bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &nums)
{
    sort(nums.begin(),nums.end());
    vector<vector <int> > ans;
    for( int i=0;i<n;i++){
       if(i>0 && nums[i]==nums[i-1]) continue;
       //cout<<nums[i]<<endl;
       int j=i+1,k=n-1;
       int target = -nums[i];
       while(j<k){
          //cout<<nums[j]<<" "<<nums[k]<<endl;
          if( nums[j]+nums[k]< target){
              j++;
          }else if( nums[j]+nums[k] > target){
              k--;
          }else{
              vector <int> temp;
              temp.push_back(nums[i]);
              temp.push_back(nums[j]);
              temp.push_back(nums[k]);
              ans.push_back( temp);
              j++,k--;
              while(j<k && nums[j]==nums[j-1]) j++;
              while(j<k && nums[k]==nums[k+1]) k--;
          }
       }                                                       
    }
    
    return ans;
    
}
