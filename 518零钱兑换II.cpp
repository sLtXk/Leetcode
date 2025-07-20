//#include<iostream>
//#include<vector>
//#include<string>
//#include<unordered_set>
//using namespace std;
//
//class Solution {
//public:
//    int change(int amount, vector<int>& coins)
//    {
//        vector<int>dp(amount + 1), valid(amount + 1);
//        dp[0] = 1;//金额为0时只有唯一一种方案就是什么都不选
//        valid[0] = 1;
//        for (int& coin : coins)
//            for (int i = coin; i <= amount; i++)
//            {
//                valid[i] |= valid[i - coin]; //或等于，判断valid[i]是否可达，只有valid[i]或者valid[i-coin]有一个不为0才可达
//            }
//        if (!valid[amount]) return 0;   //如果结果不可达直接返回0
//        for (int coin : coins)
//        {
//            for (int i = coin; i <= amount; i++)
//            {
//                dp[i] += dp[i - coin];
//            }
//        }
//        return dp[amount];
//    }
//};
///*对于面额i，其总方案数等于i减去各硬币面额i-coin的方案数之和，即
//dp[i]=dp[i-coin1]+dp[i-coin2]+....,所以我们只需要在每一个面额处遍历
//所有coin的类型求和即可*/
//int main()
//{
//    vector<int>coins = { 1,2,5 };
//    int amount = 5;
//    Solution a;
//    cout << a.change(coins, amount);
//}