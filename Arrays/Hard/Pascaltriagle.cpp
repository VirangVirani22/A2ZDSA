//given row and col find value
//(n-1)C(r-1)
ll ncr( int n,int r){
        int ncr = 1;
        for(int i=1;i<=r;i++){
            ncr = ncr * (n-i+1);
            ncr = ncr / i;
        }
        return ncr;
}


//find nth row

//bruteforce : evertime call ncr fun

class Solution{
public:
    ll ncr( int n,int r){
        int ncr = 1;
        for(int i=1;i<=r;i++){
            ncr = ncr * (n-i+1);
            ncr = ncr / i;
        }
        return ncr;
    }
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector <ll> ans;
        for(int i=1;i<=n;i++){
            ll t = ncr(n-1,i-1);
            ans.push_back(t);
        }
        return ans;
        
    }
};

//optimal 

 vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        
        vector <ll> ans;
        ans.push_back(1);
        ll var = 1;
        for(int i=1;i<n;i++){
            var = var * (n-i);
            var = var/i;
            ans.push_back(var%mod);
        }
        return ans;
        
    }

//another soln which will be accepted in gfg
vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector <vector <ll> > ans(n+1,vector<ll>(n+1,0));
        
        for(int i=1;i<=n;i++){
           
            for(int j=1;j<=i;j++){
                if(j==1 || i==j)  ans[i][j] = 1;
                else ans[i][j] = (ans[i-1][j-1]%mod + ans[i-1][j]%mod) %mod;
            }
        }
        vector <ll> res;
        for(int i=1;i<=n;i++){
            res.push_back(ans[n][i]);
        }
        return res;
        
        
        
    }

//print entire pascal triangle
//1. two loops and call everytime ncr
//2. one loop and call generaterow
//3. using previous row
class Solution {
public:
    vector<vector<int>> generate(int r) {
        vector <vector <int> > ans;
        for(int i=0;i<r;i++)
        {
            vector<int> temp(i+1);
            temp[0]=1;
            temp[i]=1;
            for(int j=1;j<i;j++)
            {
                temp[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(temp);
            
        }
        return ans;
    }
};

