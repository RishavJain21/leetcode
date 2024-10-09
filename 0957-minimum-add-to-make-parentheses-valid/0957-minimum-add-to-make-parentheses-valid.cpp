class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=s.size();
        int oc=0;
        for(auto i:s){
            if(i=='(') oc++;
            if(i==')' && oc>0){
                ans-=2;
                oc--;
            }
        }
        return ans;
    }
};