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
//        }//ѭ��������õ�targetӦ�ò�����е�λ��
//        if (left - 1 < 0) return false; //���target��һ�п�ͷ��Сֱ�ӷ���
//        int target_row = left - 1;//�����������ǱȽϵ���һ�еĿ�ͷ������targetӦ���ڲ���λ�õ�ǰһ����
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
//};//�Լ�д���ȶ��ֲ����У��ٶ��ֲ����У�ʱ�临�Ӷ�O(logm+logn)
//
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int m = matrix.size(), n = matrix[0].size();
//        int left = 0, right = m * n - 1;//ֱ�Ӷ�����������ж��ֲ���
//
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            int row = mid / n, col = mid % n;  // �����Ӧ���С�������           
//            if (matrix[row][col] == target) return true;
//            else if (matrix[row][col] < target) left = mid + 1;
//            else right = mid - 1;
//        }
//        return false;
//    }
//};//����ֱ�Ӷ�����������ֲ���Ȼ��ӳ��������ʱ�临�Ӷ�O(logmn)