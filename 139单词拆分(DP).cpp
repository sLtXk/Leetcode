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
//            set.insert(s);  //���������ֵ䣬������find����
//
//        vector<bool>dp(s.size()+1, false); //dp���飬��ʾs��ǰi���ַ��Ƿ������ֵ��е������
//        dp[0] = true;//���ַ�Ĭ�Ͽ������ֵ����ҵ�
//        for(int i=1;i<s.size()+1;i++) //������ǰi���ַ�������i���Ե���s�Ĵ�С��j������ʵ����������
//            for (int j = 0; j < i; j++)//����ǰi����ĸ�����1��j�������ֵ����ҵ�����ֻ��j+1��i�ܹ����ֵ����ҵ�����ǰi���ַ������ֵ��е��ʹ���
//            {
//                if (dp[j] && set.find(s.substr(i, i-j)) != set.end())//ת�Ʒ���Ϊdp[i]=dp[j]+��s[j+1~i]���ֵ��У�
//                {
//                    dp[i] = true;
//                }
//            }
//        return dp[s.size() - 1];
//    }
//};