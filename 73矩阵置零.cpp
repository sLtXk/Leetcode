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
//        int m = matrix.size(), n = matrix[0].size();//m��n��
//        unordered_set<int>zero_row,zero_column;//��set��¼��Ҫ������к��У������ظ������Ӷ�Ϊm+n���
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
//};//�Լ�д��
//
//class Solution {
//public:
//    void setZeroes(vector<vector<int>>& matrix) {
//        int m = matrix.size(), n = matrix[0].size();
//        bool firstRowZero = false, firstColZero = false;
//        // ����һ���Ƿ��� 0
//        for (int i = 0; i < m; i++) 
//        {
//            if (matrix[i][0] == 0) 
//            {
//                firstColZero = true;
//                break;
//            }
//        }
//
//        // ����һ���Ƿ��� 0
//        for (int j = 0; j < n; j++) 
//        {
//            if (matrix[0][j] == 0) 
//            {
//                firstRowZero = true;
//                break;
//            }
//        }
//
//        // **ʹ�õ�һ�к͵�һ�д洢��Ҫ�������Ϣ**
//        for (int i = 1; i < m; i++) 
//        {
//            for (int j = 1; j < n; j++) 
//            {
//                if (matrix[i][j] == 0) 
//                {
//                    matrix[i][0] = 0; // ��ǵ�ǰ��
//                    matrix[0][j] = 0; // ��ǵ�ǰ��
//                }
//            }
//        }
//        // **���ݵ�һ�к͵�һ�еı�ǣ����ǵ�һ�к͵�һ�е�Ԫ������**
//        for (int i = 1; i < m; i++) {
//            if (matrix[i][0] == 0) // ������Ҫ����
//            { 
//                for (int j = 1; j < n; j++) {
//                    matrix[i][j] = 0;
//                }
//            }
//        }
//        for (int j = 1; j < n; j++)
//        {
//            if (matrix[0][j] == 0) // ������Ҫ����
//            { 
//                for (int i = 1; i < m; i++)
//                    matrix[i][j] = 0;
//            }
//        }
//        // **������һ�к͵�һ��**
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
//};//���Žⷨ���ȱ�����һ�к͵�һ����û��0��Ȼ���õ�һ�к͵�һ�д洢��Ҫ������к��У�Ȼ���ٸ��ݵ�һ�е�һ�б���������㣬���ĳ����ռ�
