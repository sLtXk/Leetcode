//#include<iostream>
//#include<unordered_set>
//#include<bitset>
//#include<string>
//#include<vector>
//
//using namespace std;
//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        unordered_set<string> wordSet(wordDict.begin(), wordDict.end()); // 直接用构造函数初始化，用于O(1)查找单词
//        int n = s.size();
//        vector<bool> dp(n + 1, false); // 用于表示前i个字符是否能被字典中单词表示
//        dp[0] = true; // 空字符串默认可以被表示
//
//        for (int i = 1; i <= n; i++) //i表示字符串前i位字符
//        {
//            for (int j = 0; j < i; j++)//j为字符串s的索引，就j<i是因为前i位字符对应s[i-1],所以j最多是i-1
//            {
//                if (dp[j] && wordSet.count(s.substr(j, i - j)))//如果前j个字符已经可以表示，且第j+1到i个字符也可以表示（第j+1个字符在数组中是s[j]）
//                {
//                    dp[i] = true;//则前i个字符可以被表示
//                    break; // 一旦找到能拆分的，就不用继续循环了，优化时间复杂度
//                }
//            }
//        }
//        return dp[n];
//    }
//};
