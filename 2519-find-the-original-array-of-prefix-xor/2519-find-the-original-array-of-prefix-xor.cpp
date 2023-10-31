class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int temp=pref[0];
        for(int i=1;i<pref.size();i++){
            int temp1=pref[i];
            pref[i]=pref[i]^temp;
            temp=temp1;
        }
        return pref;
    }
};