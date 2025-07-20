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
//        unordered_set<string> wordSet(wordDict.begin(), wordDict.end()); // ֱ���ù��캯����ʼ��������O(1)���ҵ���
//        int n = s.size();
//        vector<bool> dp(n + 1, false); // ���ڱ�ʾǰi���ַ��Ƿ��ܱ��ֵ��е��ʱ�ʾ
//        dp[0] = true; // ���ַ���Ĭ�Ͽ��Ա���ʾ
//
//        for (int i = 1; i <= n; i++) //i��ʾ�ַ���ǰiλ�ַ�
//        {
//            for (int j = 0; j < i; j++)//jΪ�ַ���s����������j<i����Ϊǰiλ�ַ���Ӧs[i-1],����j�����i-1
//            {
//                if (dp[j] && wordSet.count(s.substr(j, i - j)))//���ǰj���ַ��Ѿ����Ա�ʾ���ҵ�j+1��i���ַ�Ҳ���Ա�ʾ����j+1���ַ�����������s[j]��
//                {
//                    dp[i] = true;//��ǰi���ַ����Ա���ʾ
//                    break; // һ���ҵ��ܲ�ֵģ��Ͳ��ü���ѭ���ˣ��Ż�ʱ�临�Ӷ�
//                }
//            }
//        }
//        return dp[n];
//    }
//};
