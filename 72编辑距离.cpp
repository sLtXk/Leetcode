//#include<vector>
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//class Solution {
//public:
//    int minDistance(string word1, string word2) {
//        int m = word1.size(), n = word2.size();
//        if (n * m == 0) return n + m;//其中一个字符串为空，直接返回
//        vector<vector<int>>dp(m + 1, vector<int>(n + 1));//dp[i][j]表示word1前i个字符转换成word2前j个字符所需最小操作数
//
//        for (int i = 0; i < m + 1; i++) dp[i][0] = i;
//        for (int j = 0; j < n + 1; j++) dp[0][j] = j;//初始化dp数组
//
//        for (int i = 1; i < m + 1; i++) {
//            for (int j = 1; j < n + 1; j++) {
//                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];//第i、j个字符对应索引要减1
//                else {
//                    int replace = dp[i - 1][j - 1] + 1;
//                    int insert = dp[i][j - 1] + 1;
//                    int del = dp[i - 1][j] + 1;
//                    dp[i][j] = min(replace, min(insert, del));
//                }
//            }
//        }
//        return dp[m][n];
//    }
//};
///*dp[i][j]表示的是将单词A的前i个字符转换为单词B前j个字符的最少操作数，因为对A插入等效于对B删除，对B插入等效于对A删除，
//对A替换等效于对B替换，所以本质上可以划分成对其中一个单词的三种操作：插入、替换、删除。
//首先如果A和B的最后一个字符是一样的，那么操作数就取决于前i-1到j-1个字符转换：
//dp[i][j]=dp[i-1][j-1]
//如果最后一个字母不一样，则可以有上述三种操作：
//1、替换，将A的最后一个字符word1[i-1]替换成B的最后一个字符word2[j-1]，这样就回到了两个单词最后一个字符是一样的情况，
//再多加一步替换的操作，所以dp[i][j]=dp[i-1][j-1]+1;
//2、插入，在A后插入B的最后一个字符word2[j-1],这时所需要的操作数相当于将A的前i个字符转换为B的前j-1个字符（因为最后一
//个字符现在相同了已经），再加上插入这一步，即dp[i][j]=dp[i][j-1]+1
//3、删除，删除A的最后一个字符word1[i-1],此时所需操作数就是将A的前i-1个字符转换成B的前j个字符再加删除本身，即dp[i][j]=dp[i-1][j]+1
//*/