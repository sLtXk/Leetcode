//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<bitset>
//using namespace std;
//
//class Solution {
//public:
//    int findMinArrowShots(vector<vector<int>>& points) {
//        if (points.size() == 1) return 1;
//        sort(points.begin(), points.end());
//        int res=1;
//        vector<int>tmp=points[0];
//        for (int i=1;i<points.size();i++)
//        {
//            if (points[i][0] < tmp[1])//���������н�������һֻ��
//            {
//                tmp[0] = points[i][0];//������˵�Ϊ��ǰ�������˵㣨��Ϊ�Ѿ������ˣ�
//                tmp[1] = min(tmp[1], points[i][1]);//�����Ҷ˵�Ϊ���������Ҷ˵��С����һ��
//            }
//            else//û�н��������tmpΪ��ǰ����
//            {
//                tmp[0] = points[i][0];
//                tmp[1] = points[i][1];
//                res++;//��Ҫ��һֻ�������������
//            }
//        }
//        return res;
//    }
//};//�Լ��ķ���
//
//class Solution {
//public:
//    int findMinArrowShots(vector<vector<int>>& points) {
//        if (points.empty()) return 0;
//
//        // ���Ҷ˵�����ȷ����������������������
//        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
//            return a[1] < b[1];
//            });
//
//        int res = 1;
//        int end = points[0][1]; // ��¼��ǰ����ļ����յ�
//        for (const auto& p : points) {
//            if (p[0] > end) { // ��ǰ������˵㳬����֮ǰ�ļ����䵽�ķ�Χ
//                res++;
//                end = p[1]; // �����¼����յ�
//            }
//        }
//        return res;
//    }
//};//�ٴ�̰���㷨
