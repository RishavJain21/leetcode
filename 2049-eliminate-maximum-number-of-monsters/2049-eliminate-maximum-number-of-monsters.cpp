class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<float,vector<float>,greater<float>> pq;

        int n=dist.size();
        for(int i=0;i<n;i++){
            pq.push((float)dist[i]/(float)speed[i]);
        }
        int ans=0;
        while(!pq.empty()){
            if(pq.top()<=ans) break;
            ans++;
            pq.pop();
        }
        return ans;
    }
};