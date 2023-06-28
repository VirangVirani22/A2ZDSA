//bruteforce : hashing

//optimal : moore's voting algorithm


class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int ele=0,cnt=0;
        for(int i=0;i<size;i++){
            if(cnt==0){
                ele = a[i];
                cnt++;
            }
            else if(a[i]==ele){
                
                cnt++;
            }else{
                cnt--;
            }
        }
        cnt=0;
        for(int i=0;i<size;i++) if(a[i]==ele) cnt++;
        if(cnt>=(size/2)+1) 
        return ele;
        return -1;
     }
};