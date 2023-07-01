//brute force  : generate all permutation  and search SC : O(N!*N)

//mention stl next_permutation

//optimal
class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        int dipindex=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                dipindex = i;
                break;
            }
        }aa
        if(dipindex==-1){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        for(int i=n-1;i>dipindex;i--){
            if(arr[i]>arr[dipindex]){
                swap(arr[i],arr[dipindex]);
                break;
            }
        }
        reverse(arr.begin()+dipindex+1,arr.end());
        return arr;
    }
};