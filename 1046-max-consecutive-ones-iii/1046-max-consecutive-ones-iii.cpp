class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int ans=0;
        int t=k;
        while(r<nums.size()){
            if(nums[r]==0){
                if(t>0) t--;
                else{while(l<r && nums[l]!=0){
                    l++;
                }
                l++;}
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};