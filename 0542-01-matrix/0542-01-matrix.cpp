class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,1e8));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0) ans[i][j]=0;
                else{
                    if(i-1>=0) {
                        if(mat[i-1][j]==0) ans[i][j]=1;
                        else ans[i][j]=min(ans[i][j],ans[i-1][j]+1);
                    }
                    if(j-1>=0){
                        if(mat[i][j-1]==0) ans[i][j]=1;
                        else ans[i][j]=min(ans[i][j],ans[i][j-1]+1);
                    }
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]!=0){
                    if(i+1<n) {
                        if(mat[i+1][j]==0) ans[i][j]=min(ans[i][j],1);
                        else ans[i][j]=min(ans[i][j],(ans[i+1][j]+1));
                    }
                    if(j+1<m){
                        if(mat[i][j+1]==0) ans[i][j]=min(ans[i][j],1);
                        else ans[i][j]=min(ans[i][j],(ans[i][j+1]+1));
                    }
                }
            }
        }
        return ans;
    }
};