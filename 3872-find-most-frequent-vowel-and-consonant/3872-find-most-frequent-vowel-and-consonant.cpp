class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> v(26,0);
        for(auto i:s){
            v[i-'a']++;
        }
        int v_max=0;
        int c_max=0;
        for(int i=0;i<26;i++){
            if(i==0 || i==4 || i==8 || i==14 || i==20){
                v_max=max(v_max,v[i]);
            }
            else{
                c_max=max(c_max,v[i]);
            }
        }
        return v_max+c_max;
    }
};