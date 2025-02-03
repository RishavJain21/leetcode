class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int a=1,b=1;
        int temp1=1,temp2=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                temp1++;
                a=max(a,temp1);
            }else temp1=1;

            if(nums[n-1-i]>nums[n-i]){
                temp2++;
                b=max(temp2,b);
            }else temp2=1;
        }
        return max(a,b);
    }
};