class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a=-1,b=-1;
        for(auto i:edges){
            if(i[0]==a || i[1]==a) return a;
            if(i[0]==b || i[1]==b) return b;
            a=i[0];b=i[1];
        }
        return -1;
    }
};