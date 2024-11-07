class Solution {
public:
    int largestCombination(vector<int>& c) {
        int v[24];
        int i;
        for(auto n:c){
            i=0;
            while(n){
                if(n&1)v[i]++;
                n=n>>1;
                i++;
            }
        }

        int ans=0;
        for(i=0;i<24;i++)ans=max(ans,v[i]);
        return ans;
    }
};