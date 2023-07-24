//bruteforce : O(N^2)
//better : use hashing space O(n)
//optimal : using maths sum of n, sum of squares of n
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        long long sum = 0,sumsq = 0;
        for(int i=0;i<n;i++) {
            sum += (long long) arr[i];
            sum-=  (long long)( i + 1);
            sumsq += ( (long long)arr[i]*arr[i]);
            sumsq -= (  (long long)(i+1) * ( i+1));
        }
        long long miss,rep;
        //mis - rep = sum
        //mis + rep = sumsq / sum
        miss = (sum + (sumsq/sum))/2;
        rep = miss - sum;
        return {miss,rep};
        
        
    }
};
//using xor
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
       int xr  =  0;
       for(int i=0;i<n;i++){
           xr = xr ^ arr[i];
           xr = xr ^ (i+1);
       }
       int setbit = 0;
    //   while(1){
    //       if(xr & (1<<setbit)!=0){
    //           break;
    //       }
    //       setbit++;
    //   }
       setbit = (xr & ~(xr - 1));
       int xra = 0, xrb = 0,cnta =0 ,cntb = 0;
       for(int i=0;i<n;i++){
           if((arr[i] & setbit)!=0){ //arr[i] & (1<<setbit)
               xra = xra ^ arr[i];
               
           }else{
               xrb = xrb ^ arr[i];
               
           }
       }
       for(int i=1;i<=n;i++){
           if(( i & setbit)!=0){
               xra = xra ^ i;
               
           }else{
               xrb = xrb ^ i;
               
           }
       }
       for(int i=0;i<n;i++){
           if(arr[i]==xra) cnta++;
       }
       if(cnta==2) return {xra,xrb};
       return {xrb,xra};
        
    }
};
