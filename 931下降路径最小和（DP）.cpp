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
//    int minFallingPathSum(vector<vector<int>>& matrix) {
//        int m = matrix.size();//行数
//        int n = matrix[0].size();//列数
//        vector<int>prev=matrix[0];
//        vector<int>curr(n);
//        for (int i = 1; i < matrix.size(); i++)
//        {
//            for (int j = 0;j < n; j++)
//            {
//                if (j == 0)
//                    curr[j] = matrix[i][j] + min(prev[j], prev[j + 1]);//第一列的数只能从正上方或者右上方下来
//                else if (j == n - 1)
//                    curr[j] = matrix[i][j] + min(prev[j], prev[j - 1]);//最后一列的数只能从正上方或者左上方下来
//                else
//                    curr[j] = matrix[i][j] + min(min(prev[j - 1], prev[j]), min(prev[j + 1], prev[j]));//左上，中间或者右上
//            }
//            prev = curr;
//        }
//        return *min_element(prev.begin(), prev.end());
//    }
//};
//
//int main()
//{
//    Solution a;
//    vector<vector<int>>matrix{ {2,1,3},{6,5,4} ,{7,8,9} };
//    cout<<a.minFallingPathSum(matrix);
//}