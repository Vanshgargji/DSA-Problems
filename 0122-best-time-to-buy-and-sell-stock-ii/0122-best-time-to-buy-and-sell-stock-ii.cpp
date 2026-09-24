class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int maxProfitSoFar = 0;
        int minPriceSoFar = prices[0];
        int totalProfit = 0;

        for(int i=1; i<n; i++){
            if(prices[i] > minPriceSoFar && prices[i] > prices[i-1]){
                maxProfitSoFar = max(maxProfitSoFar, prices[i] - minPriceSoFar);
            }
            else{
                totalProfit += maxProfitSoFar;
                maxProfitSoFar = 0;
                minPriceSoFar = prices[i];
            }
        }

        totalProfit += maxProfitSoFar;
        
        return totalProfit;
    }
};