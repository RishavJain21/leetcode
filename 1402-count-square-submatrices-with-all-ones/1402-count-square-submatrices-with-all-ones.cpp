class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans=ans+(matrix[i][0]==1);
        }
        for(int i=1;i<m;i++){
            ans=ans+(matrix[0][i]==1);
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==1){
                    matrix[i][j]=min({matrix[i-1][j],matrix[i][j-1],matrix[i-1][j-1]})+1;
                    ans=ans+matrix[i][j];
                }
                
            }
        }
        return ans;
    }
};