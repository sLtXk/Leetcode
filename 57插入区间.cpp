//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<bitset>
//using namespace std;
//
//class Solution {
//public:
//    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//        int i = 0, n = intervals.size();
//        while (i < n && intervals[i][0] < newInterval[0]) i++;//�ҵ�һ��������ͷ������������λ��
//        // ����������
//        intervals.insert(intervals.begin() + i, newInterval);
//        return merge(intervals);//ʹ��56��merge�������ǲ���Ҫ����
//    }
//    vector<vector<int>> merge(vector<vector<int>>& intervals)
//    {
//        if (intervals.size() == 1) return intervals;
//        vector<vector<int>>res;
//        for (const vector<int>interval : intervals)//����ֻ������Ԫ�أ���Ӧinterval[0]��[1]
//        {
//            if (res.size() == 0 || interval[0] > res.back()[1])//���res�л�û�д����䣬���ߵ�ǰ�����ͷ��֮ǰ�����β��
//                res.push_back(interval);//ֱ�Ӽ��뵽res��
//            else //����˵����ǰ�����ͷС��֮ǰ�����β���Ϳ���ֱ�Ӻϲ���
//                res.back()[1] = max(interval[1], res.back()[1]);
//        }
//        return res;
//    }
//};//����56�ĺ������Ȳ����ϲ�����Ϊ��������������Ͳ���Ҫ������
//
//class Solution {
//public:
//    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
//    {
//        if (intervals.size() == 0) return { newInterval };
//        vector<vector<int>>res;
//        bitset<1>occupied;
//        for (const auto interval : intervals)
//        {
//            if (interval[0] > newInterval[1])//�����ǰ��������������
//            {
//                if (!occupied[0]) //�������û�б������
//                {
//                    res.push_back(newInterval);//ֱ�Ӳ���
//                    occupied.flip();//���Ϊ�����
//                }
//                res.push_back(interval);//����ǰ�������
//            }
//            else if (interval[1] < newInterval[0])//�����ǰ�������������С
//                res.push_back(interval);//ֱ�Ӳ���
//            else//����е�ǰ����������������ص�����
//            {
//                newInterval[0] = min(interval[0], newInterval[0]);
//                newInterval[1] = max(interval[1], newInterval[1]);
//            }//�������ȡ����֮����С���Ҷ�ȡ�����intervals�ж�������ص��Ļ��ͻ��κϲ���ֱ��û���ص��ٽ�������Ĳ���
//        }
//        if (!occupied[0])res.push_back(newInterval);
//        /*���ֱ�����û�в��룬�����ֿ��ܣ�1.newInterval������������
//         2.newInterval�����һ������ϲ���ѭ������ �������������Ҫ��newInterval�����ȥ*/
//        return res;
//    }
//};