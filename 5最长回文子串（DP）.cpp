//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    string longestPalindrome(string s) {
//        int n = s.size();
//        vector<vector<bool>>dp(n, vector<bool>(n, false));//记录第i个字符到第j个字符是否为回文串
//        for (int i = 0; i < n; i++) 
//            dp[i][i] = true;
//        int maxlen = 1;//记录最大回文串长度
//        int start = 0;//记录该回文串起始位置
//        for(int len=2;len<=n;len++)              
//            for (int i = 0;i+len-1< n; i++)
//            {
//                int j = i + len - 1;
//                if (s[i] == s[j])
//                {
//                    if (len == 2) dp[i][j] = true;
//                    else dp[i][j] = dp[i + 1][j - 1];  //只有子串是回文串且当前两个字符相等才是回文串
//                }
//                if (dp[i][j] && len > maxlen)
//                {
//                    maxlen = len;
//                    start = i;
//                }
//            }
//        return s.substr(start, maxlen);
//    }
//};
///*为什么先判断不同字符在给定长度下是否为回文串，而不是判断同一字符在不同长度下是否为回文串？
//  
//  因为状态转移方程决定了：判断是否为回文串必须要用到其子串的结果，子串的长度必然是当前字符串
//  的长度-2，这就要求我们先将所有字符在较短长度下的回文串情况先求出来，才能在之后判断是否为回
//  文串。
//*/
//
//int main() {
//    string s = "babad";
//    Solution a;
//    cout << "最长回文子串: " <<a. longestPalindrome(s) << std::endl;
//    return 0;
//}