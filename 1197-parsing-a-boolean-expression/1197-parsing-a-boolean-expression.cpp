class Solution {
public:

    
    bool parseBoolExpr(string s) {
        stack<char> st;

        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]==')')st.push(s[i]);
            else if(s[i]=='('){
                i--;
                if(s[i]=='&'){
                    bool a=true;
                    while(st.top()=='f' || st.top()=='t'){
                        a=a&(st.top()=='t');
                        // cout<<"&: "<<a<<endl;
                        st.pop();
                    }
                    st.pop();
                    if(a)st.push('t');else st.push('f');
                }else if(s[i]=='|'){
                    bool a=0;
                    while(st.top()=='f' || st.top()=='t'){
                        a|=(st.top()=='t');
                        // cout<<"|: "<<a<<endl;
                        st.pop();
                    }
                    st.pop();
                    if(a){st.push('t');}else st.push('f');
                }else if(s[i]=='!'){
                    if(st.top()=='f'){
                        st.pop();
                        st.pop();
                        st.push('t');
                    }else{
                        st.pop();
                        st.pop();
                        st.push('f');
                    }
                }
            }else if(s[i]=='f' || s[i]=='t'){
                st.push(s[i]);
            }
        }
        // cout<<"top: "<<st.top()<<endl;
        return st.top()=='t';
    }
};