//bruteforce : O(N^2)
//optimal : mergesort approch
class Solution{
  public:
    long long cnt=0;
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[],long long l,long long mid,long long r){
        int temp[r-l+1];
        int ind=0,x=l,y=mid+1;
        while(x<=mid && y<=r){
            if(arr[x]<=arr[y]){
                temp[ind++] = arr[x++];
            }
            else{
                cnt+=(mid-x+1);
                temp[ind++] = arr[y++];
            }
        }
        while(x<=mid){
            temp[ind++] = arr[x++];
        }
        while(y<=r){
            temp[ind++] = arr[y++];
        }
        for(int i=l;i<=r;i++){
            arr[i] = temp[i-l];
        }
    }
    void mergesort(long long arr[], long long l,long long r){
        if(l>=r) return ;
        int mid = (l+r)/2;
        
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        mergesort(arr,0,n-1);
        //for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        return cnt;
    }

};

//without global count
class Solution{
  public:
    
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[],long long l,long long mid,long long r){
        long long cnt=0;
        long long temp[r-l+1];
        int ind=0,x=l,y=mid+1;
        while(x<=mid && y<=r){
            if(arr[x]<=arr[y]){
                temp[ind++] = arr[x++];
            }
            else{
                cnt+=(long long)(mid-x+1);
                temp[ind++] = arr[y++];
            }
        }
        while(x<=mid){
            temp[ind++] = arr[x++];
        }
        while(y<=r){
            temp[ind++] = arr[y++];
        }
        for(int i=l;i<=r;i++){
            arr[i] = temp[i-l];
        }
        return cnt;
    }
    long long mergesort(long long arr[], long long l,long long r){
        long long cnt=0;
        if(l>=r) return cnt;
        long long mid = (l+r)/2;
        
        cnt+=(long long)mergesort(arr,l,mid);
        cnt+=(long long)mergesort(arr,mid+1,r);
        cnt+=(long long)merge(arr,l,mid,r);
        return cnt;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        return mergesort(arr,0,n-1);
        //for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        
    }

};