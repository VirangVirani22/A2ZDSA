class Solution{
public:
    int evenlyDivides(int N){
        int cnt=0,og=N;
        while(N>0){
            int r = N%10;
            if(r!=0 && og%r==0) cnt++;
            N/=10;
            
        }
        return cnt;
    }
};
