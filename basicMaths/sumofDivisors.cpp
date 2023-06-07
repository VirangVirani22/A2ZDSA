#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
   long long div(int n){
       long long sum=0;
       for(int i=1;i*i<=n;i++){
           if(n%i==0){
              int a = n/i;
              int b = n/a;
              if(a==b) sum+=a;
              else sum+=(a+b);
           }
       }
       return sum;
   }
    long long sumOfDivisors(int N)
    {
        // Write Your Code here
        long long sum=0;
        for(int i=1;i<=N;i++){
            // sum+=div(i);
            sum+=i*(N/i);
        }
        return sum;
    }
};