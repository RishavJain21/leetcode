class Solution {
public:
    
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};    
    void solve(int x, int y ,int mid,vector<vector<int>>&vis,vector<vector<int>>&heights){
        
        if(!vis[x][y]){                                
            vis[x][y]=1;
            int n= heights.size();
            int m= heights[0].size();
            
            for(int i=0;i<4;i++){
                int X= x+dir[i].first;
                int Y= y+dir[i].second;
                if(X < 0 || Y<0 ||X>=n || Y>=m) continue;
                if(abs(heights[x][y]-heights[X][Y])<=mid){      
                    solve(X,Y, mid, vis , heights);
                }
            }
        }
        
        
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low=0;              
        int high=1e6;  
        int ans=-1;
        
        int n= heights.size();
        int m= heights[0].size();
        while(low<=high){
            int mid=(low+high)/2;
            
            vector<vector<int>>vis(n,vector<int>(m,0)); 
            solve(0,0,mid,vis,heights);
            if(vis[n-1][m-1]){               
                ans=mid;                     
                high=mid-1;                    
            }
            else{
                low=mid+1;
            }
            
        }
        return ans;
    }
};