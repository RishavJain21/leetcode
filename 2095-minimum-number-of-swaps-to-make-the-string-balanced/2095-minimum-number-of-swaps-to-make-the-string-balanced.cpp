class Solution {
public:
    int minSwaps(string s) {
        int i=0,j=s.length()-1;
        int oc=0,cc=0,ans=0;
        while(i<j){
            oc+=s[i]=='[';
            cc+=s[i]==']';
            if(cc>oc){
                while(s[j]!='[') j--;
                s[j--]=']';
                s[i]='[';
                cc--;oc++;ans++;
            }
            i++;
        }
        return ans;
    }
};