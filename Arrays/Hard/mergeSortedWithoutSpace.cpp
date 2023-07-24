//bruteforce : using space *

//optimal 1 : observation

class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int left = n-1,right=0;
            while(left>=0 && right<m){
                if(arr1[left]>arr2[right]){
                    swap(arr1[left],arr2[right]);
                    left--;
                    right++;
                }else{
                   break; 
                }
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m) ;
            
        } 
};

//optimal 2 : gap method (shell short)
class Solution{
    void fun(long long arr1[], long long arr2[], int i, int j){
        if(arr1[i]>arr2[j]){
            swap(arr1[i],arr2[j]);
        }
    }
    public:
      
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
           int sz = n + m;
           int gap = ( n+m )/2 + (n+m)%2;
           while(1){
               int l = 0;
               int r = l + gap;
               while(r<sz){
                   if(l<n && r>=n){
                       fun(arr1,arr2,l,r-n);
                   }else if(l<n && r<n){
                       fun(arr1,arr1,l,r);
                   }else{
                       fun(arr2,arr2,l-n,r-n);
                   }
                   l++,r++;
               }
               if(gap==1) break;
               gap = gap /2 + (gap%2);
               
           }
            
        } 
};