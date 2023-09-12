class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind,vector<int>& nums,vector<int>& v){
        if(ind==nums.size()){
            ans.push_back(v);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            v.push_back(nums[ind]);
            solve(ind+1,nums,v);
            v.pop_back();
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v={};
        solve(0,nums,v);
        return ans;
    }
};