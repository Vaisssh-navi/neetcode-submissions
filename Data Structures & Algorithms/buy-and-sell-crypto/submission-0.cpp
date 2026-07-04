class Solution {
public:
// brtue force is O(n^2)
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minprice=prices[0];
        int maxi=0;
        for(int i=1;i<n;i++){
            
                maxi=max(maxi,prices[i]-minprice);
          
                minprice=min(minprice,prices[i]);
            
        }
        return maxi;

    }
};
