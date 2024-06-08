class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int a=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            a=(a+nums[i])%k;

            if(mp.find(a)!=mp.end()){
                if(i-mp[a]>1) return 1;
            }else{
                mp[a]=i;
            }
        }
        return 0;
    }
};