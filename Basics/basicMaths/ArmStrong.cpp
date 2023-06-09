#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        int og = n,arm =0;
        while(n>0){
            int r = n%10;
            arm+=(r*r*r);
            n/=10;
        }
        if(arm==og) return "Yes";
        return "No";
    }
};