//#include<iostream>
//#include<vector>
//#include<string>
//#include<unordered_set>
//using namespace std;
//
//
//class Solution {
//public:
//    int longestPalindromeSubseq(string s) {
//        int n = s.size();
//        vector<vector<int>>dp(n, vector<int>(n, 0));//
//        for (int i = n - 1; i >= 0; i--) 
//        {
//            dp[i][i] = 1;
//            for (int j = i + 1; j < n; j++)
//            {
//                s[i] == s[j] ? dp[i][j] = dp[i + 1][j - 1] + 2 : dp[i][j] = max(dp[i + 1][j], dp[i][j -1]);
//            }
//        }
//        return dp[0][n - 1];
//    }
//};
///*遍历顺序由状态转移方程决定，由于当前状态由i+1和j-1决定，
//所以状态需要从左下方获取，因此我们需要从右下角开始，沿对
//角线从左往右，从下往上开始遍历。
//
//dp表示索引i到索引j中最长回文子序列的长度，因此单个字符dp[i][i]==1,
//
//如果i和j的字符相同，那么其回文子序列长度就等于原来的基础上+2，
//
//如果不同，那么其回文串子序列长度就只能从i+1到j 和 i到j-1两个子串
//的子序列中，选择更长的那一方。
//*/
//
//class Solution {
//public:
//    int longestPalindromeSubseq(string s) {
//        int n = s.size();
//        vector<int> dp(n, 0), prev(n, 0);
//        for (int i = n - 1; i >= 0; i--)
//        {
//            dp[i] = 1;
//            for (int j = i + 1; j < n; j++)
//            {
//                prev = dp;
//                s[i] == s[j] ? dp[j] = prev[j - 1] + 2 : dp[j] = max(prev[j], dp[j - 1]);
//            }
//        }
//        return dp[n - 1];  // 最终答案在 dp[0][n-1]
//    }
//};
///*两个一维数组的空间优化*/
//
//
//int main()
//{
//    string s = "bcdefdcb";
//    Solution a;
//    cout<< a.longestPalindromeSubseq(s);
//}
