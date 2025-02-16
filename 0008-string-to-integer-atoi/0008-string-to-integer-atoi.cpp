class Solution {
public:
    int myAtoi(string s) {
        bool pos=1,first=true;
        long long num=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(first) continue;
            }
            if(first && (s[i]=='+' || s[i]=='-')){
                pos=s[i]=='+';
            }
            else if(!(s[i]<='9' && s[i]>='0')){
                return pos?num:-1*num;
            }else{
                num=num*10+(s[i]-'0');
                if(num>=2147483648){
                    return pos?2147483647:-2147483648;
                }
            }
            first=0;
        }
        return pos?num:-1*num;
    }
};