//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<bitset>
//using namespace std;
//vector<vector<int>> merge(vector<vector<int>>& intervals)
//{
//    if (intervals.size() == 1) return intervals;
//    sort(intervals.begin(), intervals.end());//���ڶ�ά���飬sort�����ֵ�����С������������ȱȽ�����ͷinterval[0]�Ĵ�С���ٱȽ�����βinterval[1]�Ĵ�С
//    vector<vector<int>>res;
//    for (const vector<int>interval : intervals)//����ֻ������Ԫ�أ���Ӧinterval[0]��[1]
//    {
//        if (res.size() == 0 || interval[0] > res.back()[1])//���res�л�û�д����䣬���ߵ�ǰ�����ͷ��֮ǰ�����β��
//            res.push_back(interval);//ֱ�Ӽ��뵽res��
//        else //����˵����ǰ�����ͷС��֮ǰ�����β���Ϳ���ֱ�Ӻϲ���
//            res.back()[1] = max(interval[1], res.back()[1]);
//    }
//    return res;
//}