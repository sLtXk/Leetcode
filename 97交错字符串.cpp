//class Solution {
//public:
//    bool isInterleave(string s1, string s2, string s3) {
//        int m = s1.size(), n = s2.size();
//        if (m + n != s3.size()) return false;
//        vector<vector<bool>>dp(m + 1, vector<bool>(n + 1, false));//dp[i][j]代表s1的前i个字符和s2的前j个字符能否交错组成s3的前i+j个字符
//        dp[0][0] = true;//空字符串肯定能组成空字符串
//
//        for (int i = 1; i <= m; i++) dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);//第i个字符索引为i-1
//        for (int j = 1; j <= n; j++) dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
//
//        for (int i = 1; i < m + 1; i++) {
//            for (int j = 1; j < n + 1; j++) {
//                if (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) dp[i][j] = true;
//                if (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1])) dp[i][j] = true;
//            }
//        }
//        return dp[m][n];
//    }
//};//二维DP
//
///*i 和 j 已经遍历了所有可能的状态，它们本质上就是 s1 和 s2 的长度的所有组合。
//
//在 dp[i][j] 这个状态里：
//
//i 表示当前使用的 s1 的字符数量
//
//j 表示当前使用的 s2 的字符数量
//
//i + j 恰好 对应 s3 的长度
//
//所以，当我们考虑 dp[i][j] 的状态转移时，i 和 j 本身已经确保了所有s1,s2的各种长度情况都被遍历过了：
//
//如果可以从 dp[i-1][j] 转移过来，说明前 i-1 个 s1 加 j 个 s2 已经能组成 s3 的前 i+j-1 个字符，那 s1[i-1] 只要等于 s3[i+j-1]，就能组成 dp[i][j]。
//
//同理，如果可以从 dp[i][j-1] 转移过来，说明 s1 的前 i 个字符和 s2 的前 j-1 个字符已经组成了 s3 的前 i+j-1 个字符，那 s2[j-1] 只要等于 s3[i+j-1]，就能组成 dp[i][j]。
//
//所以：
//
//每个 dp[i][j] 只需要依赖于 dp[i-1][j] 和 dp[i][j-1]，不需要考虑更复杂的组合。
//
//所有可能的 s1 和 s2 的取法，都会在 i 和 j 遍历的过程中被覆盖到，不需要额外考虑"跳步"的情况。*/
//
//class Solution {
//public:
//    bool isInterleave(string s1, string s2, string s3) {
//        int m = s1.size(), n = s2.size();
//        if (m + n != s3.size()) return false;
//        vector<vector<bool>>dp(m + 1, vector<bool>(n + 1, false));//dp[i][j]代表s1的前i个字符和s2的前j个字符能否交错组成s3的前i+j个字符
//        dp[0][0] = true;//空字符串肯定能组成空字符串
//
//        for (int i = 1; i <= m; i++) dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);//第i个字符索引为i-1
//        for (int j = 1; j <= n; j++) dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
//
//        for (int i = 1; i < m + 1; i++) {
//            for (int j = 1; j < n + 1; j++) {
//                if (dp[i - 1][j] && (s1[i - 1] == s3[i + j - 1])) dp[i][j] = true;
//                if (dp[i][j - 1] && (s2[j - 1] == s3[i + j - 1])) dp[i][j] = true;
//            }
//        }
//        return dp[m][n];
//    }
//};/*注意到dp[i][j]只取决于dp[i-1][j]和dp[i][j-1]的状态，因此我们可以像棋盘类型的二维dp一样，
//  用一行保存当前的数据，在下一行更新时，只取决于前一行（即dp[j]自己）的状态,或者取决于前一列
//  即dp[j-1]的状态*/