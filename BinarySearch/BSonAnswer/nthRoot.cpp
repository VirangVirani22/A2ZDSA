int fun(long long mid, int n, int m){
  long long mul =1;
  for (int i = 1; i <= n; i++) {
       mul = mul * mid;
       if (mul > m) {
         return 2;
       }
     }
     if(mul == m) return 0;
     return 1;
}
int NthRoot(int n, int m) {
  // Write your code here.
   long long l = 1, r = m , ans = -1;
   while(l<=r){
     long long mid = l + (r - l)/2, mul = 1;
     mul = fun(mid,n,m);
     
     //cout<<mul<<endl;
     if(mul==0){
       ans = mid ;
       return ans;
     }else if(mul==2) {
       r = mid -1;
     } else{
       l = mid + 1;
     }
     
   }
   return ans;
}