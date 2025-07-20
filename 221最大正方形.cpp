//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//#include<queue>
//#include<stack>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//    int maximalSquare(vector<vector<char>>& matrix) {
//        int m = matrix.size(), n = matrix[0].size();
//        vector<vector<int>>dp(m, vector<int>(n));//dp[i][j]������i,jΪ���½ǵ���������εı߳�
//        int maxside = 0;
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (matrix[i][j] == '1') {
//                    if (i == 0 || j == 0) dp[i][j] = 1;
//                    else {
//                        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
//                    }
//                    maxside = max(maxside, dp[i][j]);
//                }
//            }
//        }
//        return maxside * maxside;
//    }
//};
///*�����������������������α߳����������ǵ���Сֵ�����ġ���������κ�һ
//�������޷���������Ϊ�����Σ������Ͻ�Ϊ 0������ô��ǰ��Ҳ�޷���չ��
//��ˣ�min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) ȡ��С�ı߳�����Ϊ��ǰ��Ļ�����*/
//
//class Solution {
//public:
//    int maximalSquare(vector<vector<char>>& matrix) {
//        int m = matrix.size(); // ����
//        int n = matrix[0].size(); // ����
//
//         �����������飬���ڱ���ǰһ�к͵�ǰ�е� DP ״̬
//        vector<int> dp_prev(n, 0); // ������һ���Ըõ�Ϊ���½�������ɵ������α߳�
//        vector<int> dp_curr(n, 0); // ����ǰ���Ըõ�Ϊ���½�������ɵ������α߳�
//
//        int maxside = 0; // ��������α߳���ʼ��Ϊ 0
//
//         ��ʼ����һ�� DP ����
//        for (int j = 0; j < n; j++) {
//            if (matrix[0][j] == '1') {
//                dp_prev[j] = 1; // ��һ�е����������߳�ֻ��Ϊ 1
//                maxside = max(maxside, dp_prev[j]); // �������߳�
//            }
//        }
//         �����ӵڶ��п�ʼ�ľ���
//        for (int i = 1; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (matrix[i][j] == '1') {
//                    if (j == 0) {
//                         ��һ��ֻ���γɱ߳�Ϊ 1 ��������
//                        dp_curr[j] = 1;
//                    }
//                    else {
//                         ������ (i, j) Ϊ���½ǵ������α߳�
//                        dp_curr[j] = min(min(dp_prev[j - 1], dp_prev[j]), dp_curr[j - 1]) + 1;
//                    }
//                     �������߳�
//                    maxside = max(maxside, dp_curr[j]);
//                }
//                else {
//                    dp_curr[j] = 0; // �����ǰ��Ϊ '0'�������α߳�Ϊ 0
//                }
//            }
//            dp_prev = dp_curr; // ������һ�еĹ�������
//        }
//         ������������ε����
//        return maxside * maxside;
//    }
//};
