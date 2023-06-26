//check if array is sorted
class Solution {
  public:
    bool arraySortedOrNot(int arr[], int n) {
        // code here
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i-1]) return false;
        }
        return true;
    }
};

//remove dulicates from sorted array and place uniques at the begining, also return the number of uniques

//brute-force : using set/map

//optimal

class Solution{
public:
    int remove_duplicate(int arr[],int n){
        // code here
        
        int ogi = 0;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[ogi]){
                continue;
            }else{
                ogi++;
                arr[ogi] = arr[i];
            }
        }
        return ogi+1;
    }
};