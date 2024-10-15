class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int zc=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='0')zc++;
            else{
                ans+=(long long)zc;
            }
        }
        return ans;
    }
};