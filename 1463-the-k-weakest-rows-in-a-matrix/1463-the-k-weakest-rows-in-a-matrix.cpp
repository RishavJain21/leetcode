class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i=0;i<mat.size();i++){
            int c=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1) c++;
                else break;
            }
            if(pq.size()<k)pq.push({c,i});
            else if(c<pq.top().first){
                pq.pop();
                pq.push({c,i});
            }
        }
        while(!pq.empty()){
            auto i=pq.top();
            pq.pop();
            ans.push_back(i.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};