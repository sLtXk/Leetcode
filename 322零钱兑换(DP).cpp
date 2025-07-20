//#include<iostream>
//#include<vector>
//#include<string>
//#include<unordered_set>
//using namespace std;
//
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        if (amount == 0) return 0;
//        int n = coins.size();
//        vector<int> dp(amount + 1, INT_MAX);
//        dp[0] = 0; // 总金额为 0，不需要硬币
//
//        for (int i = 1; i <= amount; i++) { // 遍历所有金额
//            for (int coin : coins) { // 遍历所有硬币面额
//                if (i >= coin && dp[i - coin] != INT_MAX) { // 只有前一个面额可达时才更新
//                    dp[i] = min(dp[i], dp[i - coin] + 1);
//                }
//            }
//        }
//        return dp[amount] == INT_MAX ? -1 : dp[amount];
//    }
//};
//
//int main()
//{
//    vector<int>coins = {1,214783647};
//    int amount = 11;
//    Solution a;
//    cout << a.coinChange(coins, amount);
//}