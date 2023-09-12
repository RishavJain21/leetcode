class Solution {
public:
    set<vector<int>> se;
    vector<vector<int>> ans;
    void solve(int ind,vector<int>& nums,vector<int>& v){
        if(ind==nums.size()){
            if(se.find(v)==se.end()){
                ans.push_back(v);
                se.insert(v);
            }
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> v={};
        solve(0,nums,v);
        return ans;
    }
};