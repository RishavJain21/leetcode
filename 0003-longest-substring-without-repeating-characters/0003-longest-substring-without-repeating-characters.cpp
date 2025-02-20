class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,ans=0;
        vector<int> v(256,-1);
        while(r<s.length()){
            if(v[s[r]]!=-1){
                l=max(v[s[r]]+1,l);
            }
            v[s[r]]=r;
            ans=max(r-l+1,ans);
            r++;
        }
        return ans;
    }
};