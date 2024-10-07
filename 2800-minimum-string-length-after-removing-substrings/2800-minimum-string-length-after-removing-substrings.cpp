class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto i:s){
            if(i=='D' && !st.empty()){
                if(st.top()=='C') {
                    st.pop();
                    continue;
                }
            }else if(i=='B' && !st.empty()){
                if(st.top()=='A') {
                    st.pop();
                    continue;
                }
            }
            st.push(i);
        }
        return st.size();
    }
};