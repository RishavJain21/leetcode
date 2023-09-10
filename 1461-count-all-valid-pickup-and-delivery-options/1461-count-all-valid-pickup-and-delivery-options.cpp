#define ll long long
class Solution {
public:
    const int MOD=1e9+7;
    
    // int solve(int n){
    //     if(n==1) return 1;
    //     return n*(2*n-1)*solve(n-1);
    // }

    int countOrders(int n) {
        ll dp[n+1];
        dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]*(i*(2*i-1))%MOD)%MOD;
            // dp[i]%=MOD;
        }
        return dp[n]%MOD;
    }
};