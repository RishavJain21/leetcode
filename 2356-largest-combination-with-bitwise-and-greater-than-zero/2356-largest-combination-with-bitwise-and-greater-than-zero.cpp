class Solution {
public:
    void solve(vector<int>&c,vector<int>& v){
        for(auto n:c){
            int i=0;
            while(n){
                if(n&1)v[i]++;
                n=n>>1;
                i++;
            }
        }
    }
    int largestCombination(vector<int>& c) {
        vector<int> v(24,0);
        solve(c,v);
        int ans=0;
        for(auto i:v)ans=max(ans,i);
        return ans;
    }
};