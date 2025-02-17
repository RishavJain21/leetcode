class Solution {
public:

    void solve(int ind,vector<int> v,vector<int>& nums,vector<vector<int>> &ans){
        if(ind==nums.size()){
            ans.push_back(v);
            return;
        }
        solve(ind+1,v,nums,ans);
        v.push_back(nums[ind]);
        solve(ind+1,v,nums,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,{},nums,ans);
        return ans;
    }
};