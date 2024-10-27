class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int> v1(m+1,0),v2(m+1,0);

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    v2[j+1]=min({v1[j+1],v2[j],v1[j]})+1;
                    ans+=v2[j+1];
                }
            }
            for(int k=1;k<=m;k++){
                v1[k]=v2[k];
                v2[k]=0;
            }
        }
        return ans;
    }
};