//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//    string longestPalindrome(string s) {
//        int n = s.size();
//        vector<vector<bool>>dp(n, vector<bool>(n, false));//��¼��i���ַ�����j���ַ��Ƿ�Ϊ���Ĵ�
//        for (int i = 0; i < n; i++) 
//            dp[i][i] = true;
//        int maxlen = 1;//��¼�����Ĵ�����
//        int start = 0;//��¼�û��Ĵ���ʼλ��
//        for(int len=2;len<=n;len++)              
//            for (int i = 0;i+len-1< n; i++)
//            {
//                int j = i + len - 1;
//                if (s[i] == s[j])
//                {
//                    if (len == 2) dp[i][j] = true;
//                    else dp[i][j] = dp[i + 1][j - 1];  //ֻ���Ӵ��ǻ��Ĵ��ҵ�ǰ�����ַ���Ȳ��ǻ��Ĵ�
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
///*Ϊʲô���жϲ�ͬ�ַ��ڸ����������Ƿ�Ϊ���Ĵ����������ж�ͬһ�ַ��ڲ�ͬ�������Ƿ�Ϊ���Ĵ���
//  
//  ��Ϊ״̬ת�Ʒ��̾����ˣ��ж��Ƿ�Ϊ���Ĵ�����Ҫ�õ����Ӵ��Ľ�����Ӵ��ĳ��ȱ�Ȼ�ǵ�ǰ�ַ���
//  �ĳ���-2�����Ҫ�������Ƚ������ַ��ڽ϶̳����µĻ��Ĵ�������������������֮���ж��Ƿ�Ϊ��
//  �Ĵ���
//*/
//
//int main() {
//    string s = "babad";
//    Solution a;
//    cout << "������Ӵ�: " <<a. longestPalindrome(s) << std::endl;
//    return 0;
//}