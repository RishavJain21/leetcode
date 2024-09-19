class Solution {
public:
    vector<int> solve(string s,int i,int j){
        vector<int> ans;
        bool m=true;
        string temp="";
        for(int k=i;k<=j;k++){
            vector<int> a,b;
            if(s[k]=='-'){
                a=solve(s,i,k-1);
                b=solve(s,k+1,j);
                for(int c=0;c<a.size();c++){
                    for(int d=0;d<b.size();d++){
                        ans.push_back(a[c]-b[d]);
                    }
                }
                m=0;
            }else if(s[k]=='+'){
                a=solve(s,i,k-1);
                b=solve(s,k+1,j);
                for(int c=0;c<a.size();c++){
                    for(int d=0;d<b.size();d++){
                        ans.push_back(a[c]+b[d]);
                    }
                }
                m=0;
            }else if(s[k]=='*'){
                a=solve(s,i,k-1);
                b=solve(s,k+1,j);
                for(int c=0;c<a.size();c++){
                    for(int d=0;d<b.size();d++){
                        ans.push_back(a[c]*b[d]);
                    }
                }
                m=0;
            }
            else {
                temp+=s[k];
            }
        }
        int n=stoi(temp);
        if(m) ans.push_back(n);
        return ans;
    }
    vector<int> diffWaysToCompute(string s) {
        return solve(s,0,s.size()-1);
    }
};