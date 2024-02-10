icnt floorSqrt(int n)
{
    // Write your code here.
    long long l =1, r = n,ans=0;
    while(l<=r){
        long long mid = l + (r-l)/2;
        long long t = mid * mid;
        if(t<=n){
            ans = mid;
            l = mid + 1;
            
        }else{
            r = mid - 1;
        }
    }
    return ans;
}
int floorSqrt(int n)
{
    // Write your code here.
    long long l =1, r = n/2 + 1 ,ans=0;
    while(l<=r){
        long long mid = l + (r-l)/2;
        long long t = mid * mid;
        if(t<=n){
            ans = mid;
            l = mid + 1;
            
        }else{
            r = mid - 1;
        }
    }
    return ans;
}
