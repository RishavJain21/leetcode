class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> ans(n+1, 1);
        for(int i=1; i<=n/2; i++){
            ans[i]=ans[n-i]=(long long)ans[i-1]*(n-i+1)/i;
        }
        return ans;
    }
};