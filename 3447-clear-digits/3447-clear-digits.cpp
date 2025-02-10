class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(auto i:s){
            if(i<='9' && i>='0'){
                st.pop();
            }
            else st.push(i);
        }
        s="";
        while(st.size()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};