class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int a=0,b=0,c=0;
        if(i-1>=0 && j+1<grid[0].size() && grid[i-1][j+1]>grid[i][j])
            a=solve(i-1,j+1,grid,dp)+1;
        if(j+1<grid[0].size() && grid[i][j+1]>grid[i][j])b=solve(i,j+1,grid,dp)+1;
        if(i+1<grid.size() && j+1<grid[0].size() && grid[i+1][j+1]>grid[i][j]) c=solve(i+1,j+1,grid,dp)+1;
        return dp[i][j]=max({a,b,c}); 
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,solve(i,0,grid,dp));
        }
        return ans;
    }
};