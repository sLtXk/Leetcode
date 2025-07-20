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
//        int m = matrix.size();//����
//        int n = matrix[0].size();//����
//        vector<int>prev=matrix[0];
//        vector<int>curr(n);
//        for (int i = 1; i < matrix.size(); i++)
//        {
//            for (int j = 0;j < n; j++)
//            {
//                if (j == 0)
//                    curr[j] = matrix[i][j] + min(prev[j], prev[j + 1]);//��һ�е���ֻ�ܴ����Ϸ��������Ϸ�����
//                else if (j == n - 1)
//                    curr[j] = matrix[i][j] + min(prev[j], prev[j - 1]);//���һ�е���ֻ�ܴ����Ϸ��������Ϸ�����
//                else
//                    curr[j] = matrix[i][j] + min(min(prev[j - 1], prev[j]), min(prev[j + 1], prev[j]));//���ϣ��м��������
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