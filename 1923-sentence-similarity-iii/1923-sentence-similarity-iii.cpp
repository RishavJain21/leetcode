class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        stringstream ss1(s1),ss2(s2);
        string word;
        vector<string> a,b;
        while(ss1>>word) a.push_back(word);
        while(ss2>>word) b.push_back(word);
        int n=a.size(),m=b.size();        
        int pr=0,su=0;
        for(int i=0;i<min(n,m);i++){
            // cout<<a[i]<<" "<<b[i]<<endl;
            if(a[i]==b[i])pr++;
            else break;
        }
        int j1=n-1,j2=m-1;
        
        while(j1>=0 && j2>=0){
            if(a[j1--]==b[j2--]) su++;
            else break;
        }
        // cout<<pr<<" "<<su<<endl;
        if((pr+su)>=n || (pr+su)>=m || pr==n || pr==m || su==n || su==m) return 1;
        else return 0;


    }
};