class Cashier {
public:
		int a,b,c;
		map<int,int> mp;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        for(int i=0;i<prices.size();i++){
						mp[products[i]]=prices[i];
				}
				a=n;
				b=0;
				c=100-discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        b++;
				double ans=0;
				for(int i=0;i<amount.size();i++){
					ans+=(mp[product[i]]*amount[i]);
				}
				if(b%a==0) return ans*((double)c/(double)100);
				return ans;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */