class Solution {
public:
    string invert(string s){
        for(int i=0;i<s.length();i++){
            if(s[i]=='1') s[i]='0';
            else s[i]='1';
        }
        reverse(s.begin(),s.end());
        return s;
    }
    char findKthBit(int n, int k) {
        string s="0";
        string ans="0";
        for(int i=1;i<n;i++){
            ans=s+"1"+invert(s);
            s=ans;
        }
        return ans[k-1];
    }
};