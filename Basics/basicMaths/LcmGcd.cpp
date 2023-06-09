#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        vector <long long> ans;
        long long a=A,b=B,gcd,lcm;
        while(a>0 && b>0){
            if(a>b) a=a%b;
            else b=b%a;
        }
        if(a==0) gcd = b;
        else gcd = a;
        lcm = A*B/gcd;
        ans.push_back(lcm);
        ans.push_back(gcd);
        return ans;
        
    }
};
