class Solution {
public:
    #define ll long long
    const ll MOD=1e9+7;
    int countVowelPermutation(int n) {
        vector<ll> a(5,1),b(5,0);
        int i=2;
        while(i<=n){
            b[0]=(a[1]+(a[4]+a[2])%MOD)%MOD;;
            b[1]=(a[0]+a[2])%MOD;
            b[2]=(a[3]+a[1])%MOD;
            b[3]=a[2]%MOD;
            b[4]=(a[2]+a[3])%MOD;
            for(int j=0;j<5;j++){
                a[j]=b[j];
                b[j]=0;
            }
            i++;
        }
        ll ans=0;
        for(auto i:a) ans=(ans+i)%MOD;
        return (int)ans;
    }
};