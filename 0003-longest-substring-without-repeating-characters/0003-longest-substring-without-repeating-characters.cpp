class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,ans=0;
        unordered_set<char> st;
        while(r<s.length()){
            if(st.find(s[r])!=st.end()){
                while(l<r && s[l]!=s[r]){
                    st.erase(s[l]);l++;
                }l++;
            }
            st.insert(s[r]);
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};