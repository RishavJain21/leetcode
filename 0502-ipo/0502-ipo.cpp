class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& pr, vector<int>& ca) {
        vector<pair<int,int>> v;
        int n=pr.size();
        for(int i=0;i<n;i++){
            v.push_back({ca[i],pr[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int> pq;
        int i=0;
        for(int j=0;j<k;j++){
            while(i<n && v[i].first<=w){
                pq.push(v[i].second);
                i++;
            }
            if(pq.empty()) break;
            w+=pq.top();
            pq.pop();
        }
        return w;
    }
};