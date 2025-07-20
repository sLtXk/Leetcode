//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        int dp_buy = -prices[0], dp_null = 0;//当天买了股票和没买股票
//        for (int i = 1; i < n; i++)
//        {
//            dp_buy = max(dp_buy, dp_null - prices[i]);
//            dp_null = max(dp_null, dp_buy + prices[i]);
//        }
//        return dp_null;
//    }
//};