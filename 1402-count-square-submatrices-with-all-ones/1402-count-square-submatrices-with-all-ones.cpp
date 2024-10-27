class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> v(n+1,(vector<int>(m+1,0)));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    v[i+1][j+1]=min({v[i][j+1],v[i+1][j],v[i][j]})+1;
                    ans+=v[i+1][j+1];
                }
            }
        }
        return ans;
    }
};