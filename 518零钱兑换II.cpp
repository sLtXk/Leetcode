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
//        dp[0] = 1;//���Ϊ0ʱֻ��Ψһһ�ַ�������ʲô����ѡ
//        valid[0] = 1;
//        for (int& coin : coins)
//            for (int i = coin; i <= amount; i++)
//            {
//                valid[i] |= valid[i - coin]; //����ڣ��ж�valid[i]�Ƿ�ɴֻ��valid[i]����valid[i-coin]��һ����Ϊ0�ſɴ�
//            }
//        if (!valid[amount]) return 0;   //���������ɴ�ֱ�ӷ���0
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
///*�������i�����ܷ���������i��ȥ��Ӳ�����i-coin�ķ�����֮�ͣ���
//dp[i]=dp[i-coin1]+dp[i-coin2]+....,��������ֻ��Ҫ��ÿһ��������
//����coin��������ͼ���*/
//int main()
//{
//    vector<int>coins = { 1,2,5 };
//    int amount = 5;
//    Solution a;
//    cout << a.change(coins, amount);
//}