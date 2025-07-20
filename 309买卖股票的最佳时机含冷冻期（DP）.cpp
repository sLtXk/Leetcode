//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        vector<int>dpbuy(2, 0);
//        vector<int>dpnull(2, 0);
//        vector<int>frozen(2, 0);
//        dpbuy[0] = -prices[0], dpnull[0] = 0, frozen[0] = 0;
//        for (int i = 1; i < n; ++i)
//        {
//            dpnull[1] = max(dpnull[0], frozen[0]);//不持有股票只能是前一天就不持有或者是冷冻期
//            dpbuy[1] = max(dpbuy[0], dpnull[0] - prices[i]);//持有只能是之前就持有或者今天刚买
//            frozen[1] = dpbuy[0] + prices[i];  //冷冻期只能是前一天持有今天卖掉
//            dpbuy[0] = dpbuy[1];
//            dpnull[0] = dpnull[1];
//            frozen[0] = frozen[1];
//        }
//        return max(frozen[1], dpnull[1]);//最大值肯定不可能持有股票
//    }
//};