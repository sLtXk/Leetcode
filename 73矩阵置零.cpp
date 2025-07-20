//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//#include<unordered_map>
//#include<unordered_set>
//using namespace std;
//
//class Solution {
//public:
//    void setZeroes(vector<vector<int>>& matrix) {
//        int m = matrix.size(), n = matrix[0].size();//m行n列
//        unordered_set<int>zero_row,zero_column;//用set记录需要置零的行和列，不会重复，复杂度为m+n最多
//        for (int i = 0; i < m; i++)
//            for (int j = 0; j < n; j++)
//            {
//                if (matrix[i][j] == 0)
//                {
//                    zero_row.insert(i);
//                    zero_column.insert(j);
//                }
//            }
//        for (int i:zero_row)
//            for (int j = 0; j < n; j++)
//                matrix[i][j] = 0;
//        for (int i : zero_column)
//            for (int j = 0; j < m; j++)
//                matrix[j][i] = 0;
//    }
//};//自己写的
//
//class Solution {
//public:
//    void setZeroes(vector<vector<int>>& matrix) {
//        int m = matrix.size(), n = matrix[0].size();
//        bool firstRowZero = false, firstColZero = false;
//        // 检查第一列是否有 0
//        for (int i = 0; i < m; i++) 
//        {
//            if (matrix[i][0] == 0) 
//            {
//                firstColZero = true;
//                break;
//            }
//        }
//
//        // 检查第一行是否有 0
//        for (int j = 0; j < n; j++) 
//        {
//            if (matrix[0][j] == 0) 
//            {
//                firstRowZero = true;
//                break;
//            }
//        }
//
//        // **使用第一行和第一列存储需要置零的信息**
//        for (int i = 1; i < m; i++) 
//        {
//            for (int j = 1; j < n; j++) 
//            {
//                if (matrix[i][j] == 0) 
//                {
//                    matrix[i][0] = 0; // 标记当前行
//                    matrix[0][j] = 0; // 标记当前列
//                }
//            }
//        }
//        // **根据第一行和第一列的标记，将非第一行和第一列的元素置零**
//        for (int i = 1; i < m; i++) {
//            if (matrix[i][0] == 0) // 该行需要置零
//            { 
//                for (int j = 1; j < n; j++) {
//                    matrix[i][j] = 0;
//                }
//            }
//        }
//        for (int j = 1; j < n; j++)
//        {
//            if (matrix[0][j] == 0) // 该列需要置零
//            { 
//                for (int i = 1; i < m; i++)
//                    matrix[i][j] = 0;
//            }
//        }
//        // **最后处理第一行和第一列**
//        if (firstColZero) 
//        {
//            for (int i = 0; i < m; i++) 
//                matrix[i][0] = 0;
//        }
//        if (firstRowZero) 
//        {
//            for (int j = 0; j < n; j++) 
//                matrix[0][j] = 0;
//        }
//    }
//};//最优解法，先遍历第一行和第一列有没有0，然后用第一行和第一列存储需要置零的行和列，然后再根据第一行第一列遍历结果置零，消耗常数空间
