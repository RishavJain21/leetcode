class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i=0,ans=0;
        long long a=1;
        while(a<=n){
            if(i<nums.size() && nums[i]<=a){
                a+=nums[i];
                i++;
            }else{
                a+=a;
                ans++;
            }
        }
        return ans;
    }
};