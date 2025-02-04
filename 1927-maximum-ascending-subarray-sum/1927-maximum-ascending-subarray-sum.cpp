class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currSum=nums[0],ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                currSum+=nums[i];
            }else{
                ans=max(ans,currSum);
                currSum=nums[i];
            }
        }
        ans=max(ans,currSum);
        return ans;
    }
};