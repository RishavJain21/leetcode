class Solution {
public:
    int adj[1001][1001];
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adj[i][j]=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
            }
        }

        priority_queue<pair<int, int>,vector<pair<int, int> >,greater<pair<int, int>>> pq;
        int ans=0;
        pq.push({0,0});
        vector<bool> vis(n,0);
        while(!pq.empty()){
            auto a=pq.top();
            pq.pop();
            int u=a.second;

            if(vis[u]) continue;
            vis[u]=1;
            ans+=a.first;

            for(int v=0;v<n;v++){
                if(!vis[v]){
                    pq.push({adj[u][v],v});
                }
            }
        }
        return ans;
    }
};