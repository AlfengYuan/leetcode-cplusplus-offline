class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxPrice(prices.size(), 0);
        int res = 0;
        for(int i = prices.size()-1; i>=0; i--){
            if(i==prices.size()-1) maxPrice[i] = prices[i];
            else{
                if(prices[i] > maxPrice[i+1]) maxPrice[i] = prices[i];
                else maxPrice[i] = maxPrice[i+1];
            }
        }

        for(int i = 0; i<prices.size(); i++){
            if(maxPrice[i] - prices[i] > res){
                res = maxPrice[i] - prices[i];
            }
        }
        
        return res;

    }
};