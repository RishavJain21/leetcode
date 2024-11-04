class Solution {
public:
    string compressedString(string word) {
        char p=word[0];
        string ans="";
        int c=1;
        for(int i=1;i<word.length();i++){
            if(word[i]==p && c<9){
                c++;
            }else{
                ans.push_back((char)('0'+c));
                ans.push_back(p);
                p=word[i];
                c=1;
            }
        }
        ans.push_back((char)('0'+c));
        ans.push_back(p);
        return ans;
    }
};