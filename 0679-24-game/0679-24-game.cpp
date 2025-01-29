class Solution {
public:
    vector<string> permuOps={"+++","++-","++*","++/","---","--+","--*","--/","***","**+","**-","**/","///","//-","//+","//*","+-*","+-/","-*/","*/+"};
    bool expression_solver(string s){
        stack<float> st;
        for(auto i:s){
            if(i<='9' && i>='1') {
                float c=1.0* (int)(i-'0');
                st.push(c);
            }
            else{
                if(st.size()<2) return 0;
                else{
                    float b=st.top();
                    st.pop();
                    float a=st.top();
                    st.pop();
                    if(i=='*'){
                        st.push(a*b);
                    }else if(i=='+'){
                        st.push(a+b);
                    }else if(i=='-'){
                        st.push(a-b);
                    }else if(i=='/'){
                        st.push(a/b);
                    }
                }
            }
        }
        return abs(24.0-st.top())<=0.0001;

    }

    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(),cards.end());
        string nums="";
        for(auto i:cards){
            string str = to_string(i);
            nums+=str;
        }
        string s="";
        for(auto i:permuOps){
            s="";
            s=i+nums;    
            sort(s.begin(), s.end());
            
            for(int j=0;j<5040;j++){
                if(expression_solver(s)){
                    return true;
                }
                next_permutation(s.begin(),s.end());
            }
        }

        return false;
    }
};