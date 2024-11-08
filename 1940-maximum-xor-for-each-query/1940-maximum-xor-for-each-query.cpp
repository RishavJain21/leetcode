class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int k) {
        vector<int> ans(nums.size(),0);
        int mask = (1LL << k) - 1;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            temp=temp^nums[i];
            ans[nums.size()-1-i]=~temp&mask;
        }
        return ans;
    }
};