//bruteforce : N^2
//better : hashing
//optimal
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1,ele2,cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1) {
                cnt1++;
            }else if(nums[i]==ele2){
                cnt2++;
            }else if(cnt1==0){
                cnt1++;
                ele1= nums[i];
            }else if(cnt2==0){
                cnt2++;
                ele2= nums[i];
            }else{
                cnt1--,cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for( int i=0;i<nums.size();i++){
            if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
        }
        int maj = nums.size()/3;
        vector<int> ans;
        if(cnt1>maj) ans.push_back( ele1);
         if(cnt2>maj) ans.push_back( ele2);
         return ans;
    }
};