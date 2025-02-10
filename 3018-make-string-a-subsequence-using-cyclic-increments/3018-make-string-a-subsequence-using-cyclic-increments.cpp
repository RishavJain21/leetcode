class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if(str2.length() > str1.length()){
            return false;
        }
        int i=0,j=0;
        while(i<str1.length() && j<str2.length()){
            if(str1[i]==str2[j] || ((str1[i]-'a')+1)%26==(str2[j]-'a')){
                j++;
            }
            i++;
        }
        return j==str2.length();
    }
};