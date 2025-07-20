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
//        vector<vector<int>>dp(m, vector<int>(n));//dp[i][j]代表以i,j为右下角的最大正方形的边长
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
///*三个方向中限制最大的正方形边长，是由它们的最小值决定的。如果其中任何一
//个方向无法继续扩大为正方形（如左上角为 0），那么当前点也无法扩展。
//因此，min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) 取最小的边长，作为当前点的基础。*/
//
//class Solution {
//public:
//    int maximalSquare(vector<vector<char>>& matrix) {
//        int m = matrix.size(); // 行数
//        int n = matrix[0].size(); // 列数
//
//         两个滚动数组，用于保存前一行和当前行的 DP 状态
//        vector<int> dp_prev(n, 0); // 代表上一行以该点为右下角所能组成的正方形边长
//        vector<int> dp_curr(n, 0); // 代表当前行以该点为右下角所能组成的正方形边长
//
//        int maxside = 0; // 最大正方形边长初始化为 0
//
//         初始化第一行 DP 数组
//        for (int j = 0; j < n; j++) {
//            if (matrix[0][j] == '1') {
//                dp_prev[j] = 1; // 第一行的正方形最大边长只能为 1
//                maxside = max(maxside, dp_prev[j]); // 更新最大边长
//            }
//        }
//         遍历从第二行开始的矩阵
//        for (int i = 1; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (matrix[i][j] == '1') {
//                    if (j == 0) {
//                         第一列只能形成边长为 1 的正方形
//                        dp_curr[j] = 1;
//                    }
//                    else {
//                         计算以 (i, j) 为右下角的正方形边长
//                        dp_curr[j] = min(min(dp_prev[j - 1], dp_prev[j]), dp_curr[j - 1]) + 1;
//                    }
//                     更新最大边长
//                    maxside = max(maxside, dp_curr[j]);
//                }
//                else {
//                    dp_curr[j] = 0; // 如果当前点为 '0'，正方形边长为 0
//                }
//            }
//            dp_prev = dp_curr; // 更新上一行的滚动数组
//        }
//         返回最大正方形的面积
//        return maxside * maxside;
//    }
//};
