#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long reversedBits(long long x) {
        vector <int> bin;
        int sz=0;
        while(x>0){
            int r = x%2;
            bin.push_back(r);
            x = x/2;
            sz++;
        }
        while(sz<32){
            bin.push_back(0);
            sz++;
        }
        reverse(bin.begin(),bin.end());
        //for(auto x:bin) cout<<x;
        long long ans =0;
         for(int i=0;i<32;i++){
            ans= ans + pow(2,i)*bin[i]; 
        }
        return ans;
        // code here
    }
};