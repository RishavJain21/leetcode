class Solution {
public:
    map<string,vector<string>> mp;
    vector<string> ans;
    void dfs(string s){
        while(!(mp[s].empty())){
            string a=mp[s].back();
            mp[s].pop_back();
            dfs(a);
        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto i:tickets){
            mp[i[0]].push_back(i[1]);
        }
        for(auto &i:mp){
            sort(i.second.begin(),i.second.end(),greater<string>());
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;

    }
};