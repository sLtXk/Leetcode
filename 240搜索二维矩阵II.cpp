//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int row = matrix.size(),column=matrix[0].size();
//        for (const auto&matrixRow:matrix) {
//            if (target <= matrixRow[column - 1] && target >= matrixRow[0]) {//ȷ��Ŀ���Ƿ�����һ�еķ�Χ��
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
//};//ʱ�临�Ӷ�O(mlogn),����û���õ���������һ��Ϣ
//
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int m = matrix.size(), n = matrix[0].size();
//        int i = 0, j = n - 1; // �����Ͻǿ�ʼ
//
//        while (i < m && j >= 0) {
//            if (matrix[i][j] == target) return true;
//            else if (matrix[i][j] > target) j--; // ������
//            else i++; // ������
//        }
//
//        return false;
//    }
//};//ʱ�临�Ӷ�O(m+n)�������Ͻǿ�ʼ����������ÿ���ų���һ�л���һ��
//
//
//int main() {
//    vector<vector<int>>matrix = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,26,23,30} };
//    Solution a;
//    cout << a.searchMatrix(matrix, 5);
//}