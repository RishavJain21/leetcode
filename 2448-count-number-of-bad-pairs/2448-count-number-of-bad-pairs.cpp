class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long ans=n*(n-1)/2;
        unordered_map<int,long long> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]-i]++;
        }
        // cout<<ans<<endl;
        for(auto i:mp){
            // cout<<i.first<<" "<<i.second<<endl;
            if(i.second>1){
                ans-=(i.second*(i.second-1)/2);
            }
        }
        return ans;
    }
};