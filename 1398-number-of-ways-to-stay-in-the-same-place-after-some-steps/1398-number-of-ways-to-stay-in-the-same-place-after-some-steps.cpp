#define ll long long
class Solution {
public:
    vector<vector<ll>> dp;
    const int MOD=1e9+7;
    ll solve(int n,int k,int p){
        if(p>=n || p<0 || k<0) return 0;
        if(k==0){
            if(p==0) return 1;
            return 0;
        }
        if(dp[k][p]!=-1) return dp[k][p];
        ll a = solve(n,k-1,p+1)%MOD;
        a+=solve(n,k-1,p)% MOD;
        a+=solve(n,k-1,p-1)% MOD;
        return dp[k][p]=a%MOD;
    }
    int numWays(int k, int n) {
        dp.resize(k+1,vector<ll>(min(n,k)+1,-1));
        return solve(n,k,0);
    }
};