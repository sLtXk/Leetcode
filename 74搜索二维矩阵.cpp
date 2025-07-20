//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int m = matrix.size();
//        int n = matrix[0].size();
//        int left = 0, right = m - 1;
//        while (left <= right)
//        {
//            int mid = left + (right - left) / 2;
//            if (target == matrix[mid][0]) return true;
//            else if (target < matrix[mid][0]) right = mid - 1;
//            else left = mid + 1;
//        }//循环结束后得到target应该插入的行的位置
//        if (left - 1 < 0) return false; //如果target比一行开头还小直接返回
//        int target_row = left - 1;//但是由于我们比较的是一行的开头，所以target应该在插入位置的前一行中
//        left = 0; right = n - 1;
//        while (left <= right)
//        {
//            int mid = left + (right - left) / 2;
//            if (target == matrix[target_row][mid]) return true;
//            else if (target < matrix[target_row][mid]) right = mid - 1;
//            else left = mid + 1;
//        }
//        return false;
//    }
//};//自己写的先二分查找行，再二分查找列，时间复杂度O(logm+logn)
//
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int m = matrix.size(), n = matrix[0].size();
//        int left = 0, right = m * n - 1;//直接对整个矩阵进行二分查找
//
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            int row = mid / n, col = mid % n;  // 计算对应的行、列索引           
//            if (matrix[row][col] == target) return true;
//            else if (matrix[row][col] < target) left = mid + 1;
//            else right = mid - 1;
//        }
//        return false;
//    }
//};//可以直接对整个矩阵二分查找然后映射索引，时间复杂度O(logmn)