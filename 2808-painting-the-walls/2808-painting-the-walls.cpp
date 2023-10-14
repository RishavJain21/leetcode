class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int solve(vector<int>& cost, vector<int>& time,int ind,int w){
        if(w<=0) return 0;
        if(ind>=n) return 1000000000;
        if(dp[ind][w]!=-1) return dp[ind][w];
        int a=solve(cost,time,ind+1,w);
        int b=cost[ind]+solve(cost,time,ind+1,w-time[ind]-1);
        return dp[ind][w]=min(a,b);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n=cost.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        return solve(cost,time,0,n);
    }
};