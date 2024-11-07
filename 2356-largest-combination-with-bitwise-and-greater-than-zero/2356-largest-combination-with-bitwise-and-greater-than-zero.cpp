class Solution {
public:
    int largestCombination(vector<int>& c) {
        vector<int> v(24,0);
        for(auto n:c){
            int i=0;
            while(n){
                if(n&1)v[i]++;
                n>>=1;
                i++;
            }
        }

        int ans=0;
        for(auto i:v)ans=max(ans,i);
        return ans;
    }
};