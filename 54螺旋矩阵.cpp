#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();//m��n��
        int flag_h = 1, flag_v = 1; // ˮƽ����ֱ����flag
        int turn = 1;//turnΪ1ʱˮƽ���������0ʱ��ֱ�������
        int count = m * n;//Ԫ���ܸ���
        int i = 0, j = 0;//i��Ӧ��ֱ���������j��Ӧˮƽ�������
        int num_h = n, num_v = --m;//ˮƽ����ֱ����Ԫ������,��Ϊ�б������˺��в����ظ�����������1
        vector<int>res;
        while (count > 0)
        {
            while (turn == 1)
            {
                if (num_h==0)//�����굱ǰ��һ��
                {
                    j -= flag_h;//j�ദ����һ�Σ���Խ�磬������Ҫ����һ��
                    flag_h = -flag_h;//�����������ı�
                    turn = 0;//��Ϊ��ֱ����
                    i += flag_v;//��������ֱ����
                    num_h=--n;//��һ�ν���ˮƽ����ʱ��һ��Ԫ�أ���Ϊ����ֱ����ʱ�Ѿ���������
                    break;
                }
                else
                {
                    res.emplace_back(matrix[i][j]);
                    j += flag_h;//�����ڴ���һ�е����һ��Ԫ��ʱ�ᳬ��Χ����Ϊ����������0��ʼ��
                    num_h--;
                    count--;
                }
            }
            while (turn == 0)
            {
                if (num_v == 0)
                {
                    i -= flag_v;//i�ദ����һ�Σ���Խ�磬������Ҫ����һ��
                    flag_v = -flag_v;//��ֱ��������ı�
                    turn = 1;//��Ϊ�������
                    j += flag_h;//�������������
                    num_v = --m;//��һ�ν�����ֱ����ʱ��һ��Ԫ�أ���Ϊ��ˮƽ����ʱ�Ѿ���������
                    break;
                }
                else
                {
                    res.emplace_back(matrix[i][j]);
                    i += flag_v;
                    num_v--;
                    count--;
                }
            }
        }
        return res;
    }
};//˼·��Z���α任����
//class Solution {
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        if (matrix.empty()) return {}; // ���������
//
//        int m = matrix.size(), n = matrix[0].size();
//        int left = 0, right = n - 1, top = 0, bottom = m - 1; // �趨�ĸ��߽�
//        vector<int> res;
//
//        while (left <= right && top <= bottom) {
//            // ������
//            for (int j = left; j <= right; j++) res.push_back(matrix[top][j]);
//            top++; // ��һ���ѷ��ʣ������ϱ߽�
//
//            // ���ϵ���
//            for (int i = top; i <= bottom; i++) res.push_back(matrix[i][right]);
//            right--; // ��һ���ѷ��ʣ������ұ߽�
//
//            if (top <= bottom) { // ȷ��������δ����
//                for (int j = right; j >= left; j--) res.push_back(matrix[bottom][j]);
//                bottom--; // ��һ���ѷ��ʣ������±߽�
//            }
//
//            if (left <= right) { // ȷ��������δ����
//                for (int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
//                left++; // ��һ���ѷ��ʣ�������߽�
//            }
//        }
//        return res;
//    }
//};//gpt�ṩ�ĵĲ������˼�룬�����ĸ��߽粻���������ﵽ����Ч��

//int main()
//{
//    vector<vector<int>>mat = { {1,2,3},{4,5,6},{7,8,9} };
//    Solution a;
//    vector<int>res = a.spiralOrder(mat);
//    for (int b : res)
//        cout << b << " ";
//}