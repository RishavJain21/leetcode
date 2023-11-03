class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        for(int i=0,count=1;i<target.size();i++,count++){
            ans.push_back("Push");
            if(target[i] != count){
                ans.push_back("Pop");
                i--;
            }
        }
        return ans;
    }
};