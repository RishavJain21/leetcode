class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        string ans="";
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});
        char lc='d';
        // while(!pq.empty()){
        //     auto d=pq.top();
        //     pq.pop();
        //     if(d.first>=2){
        //         if(lc=='d' || lc!=d.second){ans=ans+d.second+d.second;
        //         lc=d.second;}
        //         // cout<<"1 : "<<ans<<endl;
        //         if(!pq.empty()){
        //             auto e=pq.top();
        //             pq.pop();
        //             ans+=e.second;
        //             lc=d.second;
        //             // cout<<"2 : "<<ans<<endl;
        //             if(e.first>1)pq.push({e.first-1,e.second});
        //             if(d.first>2)pq.push({d.first-2,d.second});
        //         }
        //     }else{
        //         ans+=d.second;
        //         // cout<<"3 : "<<ans<<endl;
        //     }
        // }
        while(!pq.empty()){
            auto d=pq.top();
            pq.pop();
            if(lc==d.second){
                if(!pq.empty()){
                    auto e=pq.top();
                    pq.pop();
                    ans=ans+e.second;
                    if(e.first>1)pq.push({e.first-1,e.second});
                }else{
                    break;
                }
            }
            if(d.first==1){
                ans=ans+d.second;
            }else{
                ans=ans+d.second+d.second;
                if(d.first>2)pq.push({d.first-2,d.second});
            }
            lc=d.second;
        }
        return ans;
    }
};