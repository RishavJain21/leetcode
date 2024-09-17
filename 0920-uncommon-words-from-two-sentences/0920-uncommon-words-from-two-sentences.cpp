class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s=s1+" "+s2;
        unordered_map<string,int> mp;
        stringstream ss(s);
        string word;
        vector<string> ans;
        while (ss >> word) {
            mp[word]++;
        }
        for(auto i:mp){
            if(i.second==1) ans.push_back(i.first);
        }
        return ans;
    }
};