class Solution {
public:
    bool isRoot(int n){
        return ((int)sqrt(n)*(int)sqrt(n))==n;
    }
    int longestSquareStreak(vector<int>& nums) {
        vector<int> v(1e5+1,0);
        int ans=1;
        sort(nums.begin(),nums.end());
        for(auto i:nums){
            v[i]=1;
            if(isRoot(i) && v[sqrt(i)]>0){
                v[i]=v[sqrt(i)]+1;
                ans=max(ans,v[i]);
            }
        }
        return ans<2?-1:ans;
    }
};