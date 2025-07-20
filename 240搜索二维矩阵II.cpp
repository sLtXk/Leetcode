//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int row = matrix.size(),column=matrix[0].size();
//        for (const auto&matrixRow:matrix) {
//            if (target <= matrixRow[column - 1] && target >= matrixRow[0]) {//确认目标是否在这一行的范围内
//                int left = 0, right = column - 1;
//                while (left <= right) {
//                    int mid = left + (right - left) / 2;
//                    if (matrixRow[mid] == target) return true;
//                    else if (matrixRow[mid] < target) left = mid + 1;
//                    else right = mid - 1;
//                }
//            }
//        }
//        return false;
//    }
//};//时间复杂度O(mlogn),但是没有用到行升序这一信息
//
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int m = matrix.size(), n = matrix[0].size();
//        int i = 0, j = n - 1; // 从右上角开始
//
//        while (i < m && j >= 0) {
//            if (matrix[i][j] == target) return true;
//            else if (matrix[i][j] > target) j--; // 向左走
//            else i++; // 向下走
//        }
//
//        return false;
//    }
//};//时间复杂度O(m+n)，从右上角开始遍历，可以每次排除掉一行或者一列
//
//
//int main() {
//    vector<vector<int>>matrix = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,26,23,30} };
//    Solution a;
//    cout << a.searchMatrix(matrix, 5);
//}