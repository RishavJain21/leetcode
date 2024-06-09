class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0,ans=0;

        int pre_sum=0;
        vector<int> v(k,0);
        v[0]++;
        for(int i=0;i<n;i++){
            pre_sum+=nums[i];
            ans+=v[(pre_sum%k + k)%k]++;
        }
        return ans;

    }
};