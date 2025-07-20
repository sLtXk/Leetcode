#include<iostream>
#include<vector>
//#include<string>
//#include<unordered_set>
//using namespace std;
//
//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) 
//    {
//        unordered_set<string>set;
//        for (auto s : wordDict)
//            set.insert(s);  //创建单词字典，方便用find函数
//
//        vector<bool>dp(s.size()+1, false); //dp数组，表示s中前i个字符是否能由字典中单词组成
//        dp[0] = true;//空字符默认可以在字典中找到
//        for(int i=1;i<s.size()+1;i++) //由于是前i个字符，所以i可以等于s的大小，j才是真实遍历的索引
//            for (int j = 0; j < i; j++)//对于前i个字母，如果1到j可以在字典中找到，则只需j+1到i能够在字典中找到，则前i个字符能由字典中单词构成
//            {
//                if (dp[j] && set.find(s.substr(i, i-j)) != set.end())//转移方程为dp[i]=dp[j]+（s[j+1~i]在字典中）
//                {
//                    dp[i] = true;
//                }
//            }
//        return dp[s.size() - 1];
//    }
//};