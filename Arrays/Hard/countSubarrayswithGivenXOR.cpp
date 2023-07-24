//brute : generate all subrrarrays go from O(N^3) to O(N^2)
//optimal : 
#include <bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int xrtill = 0;
    map <int,int> mp;
    mp[0] = 1;
    int n = a.size( );
    int ans = 0;
    for(int i=0;i<n;i++){
        xrtill = xrtill ^ a[i];
        ans += mp[xrtill ^ b];
        mp[xrtill]++;
    }
    return ans;
}