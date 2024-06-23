class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> s;
        int n=nums.size();
        int prev=0;
        int ans=1;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
            int l=*(s.rbegin())-*s.begin();
            if(l<=limit) {
                ans=max(ans,(i-prev+1));
            }else{
                while(!s.empty() && l>limit){
                    auto a=s.find(nums[prev++]);
                    s.erase(a);
                    l=*(s.rbegin())-*s.begin();
                }
            }
        }
        return ans;
    }
};