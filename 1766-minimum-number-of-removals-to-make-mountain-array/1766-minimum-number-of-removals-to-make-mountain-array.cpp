class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> v1(n,1),v2(n,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    v1[i]=max(v1[i],v1[j]+1);
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j]){
                    v2[i]=max(v2[i],v2[j]+1);
                }
            }
        }

        int ans=n;
        for(int i=0;i<n;i++){
            if(v1[i]>1 && v2[i]>1) ans=min(ans,n+1-v1[i]-v2[i]);
        }
        return ans;
    }
};