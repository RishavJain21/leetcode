class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        map<int,vector<int>> mp;

        for(int i=0;i<g.size();i++){
            mp[g[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto i:mp){
            int j=0;
            while(j<i.second.size()){
                int k=i.first;
                vector<int> v;
                while(k--){
                    v.push_back(i.second[j++]);
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
};