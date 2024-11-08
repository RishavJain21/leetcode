class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int k) {
        vector<int> v(nums.size(),0);
        v[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            v[i]=v[i-1]^nums[i];
        }

        vector<int> ans;
        int j,temp;
        for(int i=nums.size()-1;i>=0;i--){
            j=0;temp=0;
            // cout<<v[i]<<" ";
            while(j<k){
                if(!(v[i]&1)) temp=temp+(1<<j);
                v[i]=v[i]>>1;
                j++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};