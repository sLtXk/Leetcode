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
//        dp[0] = 0; // �ܽ��Ϊ 0������ҪӲ��
//
//        for (int i = 1; i <= amount; i++) { // �������н��
//            for (int coin : coins) { // ��������Ӳ�����
//                if (i >= coin && dp[i - coin] != INT_MAX) { // ֻ��ǰһ�����ɴ�ʱ�Ÿ���
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