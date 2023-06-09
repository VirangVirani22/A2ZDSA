#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //Complete this function
    void fun(int n){
        if(n==0) return;
        fun(n-1);
        cout<<n<<" ";
    }
    void printNos(int N)
    {
        fun(N);
        //Your code here
    }
};