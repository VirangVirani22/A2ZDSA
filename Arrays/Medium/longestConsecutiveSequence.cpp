//brute-force  :  O(N^2)

//better

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      
      sort(arr,arr+n);
      int ans = 1;
      int prevsmall = arr[0];
      int cnt = 1;
      for(int i=1;i<n;i++){
          if(arr[i]==prevsmall+1){
              cnt++;
              prevsmall = arr[i];
          }else if(arr[i]!=prevsmall){
              ans = max(ans,cnt);
              cnt=1;
              prevsmall = arr[i];
          }
      }
       ans = max(ans,cnt);
      return ans;
    }
};

//optimal  : using set

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      
      unordered_set<int> s;
      for(int i=0;i<n;i++){
          s.insert(arr[i]);
          
      }
      int cnt=0,ans=1;
      for(auto x:s){
          if(s.find(x-1)==s.end()){
              cnt=1;
              int ele = x+1;
              while(s.find(ele)!=s.end()){
                  cnt++;
                  ele++;
              }
              ans=max(ans,cnt);
              
          }
      }
      return ans;
    }
};
