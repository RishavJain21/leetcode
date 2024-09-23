class Solution {
public:

    unordered_map<string,int> mp;
    vector<int> dp;
    int solve(string s,int ind){
        int n=s.length();
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        string a="";
        int ans=n;
        for(int i=ind;i<n;i++){
            a.push_back(s[i]);

            int b=mp.count(a)>0?0:a.length();
            int c=solve(s,i+1);
            int d=b+c;
            ans=min(ans,d);
        }
        return dp[ind]=ans;
    }
    

    int minExtraChar(string s, vector<string>& dict) {
        int n=s.length();
        
        for(auto i:dict) mp[i]++;
        dp.resize(n,-1);

        return solve(s,0);

    }
};