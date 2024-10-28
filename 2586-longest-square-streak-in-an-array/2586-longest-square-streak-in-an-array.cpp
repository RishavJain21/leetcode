class Solution {
public:
    bool isRoot(int n){
        return ((int)sqrt(n)*(int)sqrt(n))==n;
    }
    int longestSquareStreak(vector<int>& nums) {
        map<int,int> mp;
        int ans=1;
        sort(nums.begin(),nums.end());
        for(auto i:nums){
            mp[i]=1;
            if(isRoot(i) && mp.find(sqrt(i))!=mp.end()){
                mp[i]=mp[sqrt(i)]+1;
                ans=max(ans,mp[i]);
            }
        }
        return ans<2?-1:ans;
    }
};