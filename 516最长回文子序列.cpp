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
///*����˳����״̬ת�Ʒ��̾��������ڵ�ǰ״̬��i+1��j-1������
//����״̬��Ҫ�����·���ȡ�����������Ҫ�����½ǿ�ʼ���ض�
//���ߴ������ң��������Ͽ�ʼ������
//
//dp��ʾ����i������j������������еĳ��ȣ���˵����ַ�dp[i][i]==1,
//
//���i��j���ַ���ͬ����ô����������г��Ⱦ͵���ԭ���Ļ�����+2��
//
//�����ͬ����ô����Ĵ������г��Ⱦ�ֻ�ܴ�i+1��j �� i��j-1�����Ӵ�
//���������У�ѡ���������һ����
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
//        return dp[n - 1];  // ���մ��� dp[0][n-1]
//    }
//};
///*����һά����Ŀռ��Ż�*/
//
//
//int main()
//{
//    string s = "bcdefdcb";
//    Solution a;
//    cout<< a.longestPalindromeSubseq(s);
//}
