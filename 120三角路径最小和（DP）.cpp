//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//#include<queue>
//#include<stack>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//    int minimumTotal(vector<vector<int>>& triangle) {
//        int m = triangle.size();
//        vector<int>res = { triangle[0][0] };
//        for (int i = 1; i < m; i++)
//        {
//            res.push_back(0);
//            for (int j = i; j >= 0; j--) //����ô��ҿ�ʼ����Ϊ����ʼ�Ļ�res[j-1]�Ѿ��������ˣ��Ͳ�����һ�еĽ����
//            {
//                if (j == i)//�����Ҷ�ʱ���ڲ���0����ֻ�ܴ����Ϸ��ĵ�����
//                    res[j] = triangle[i][j] + res[j - 1];//����Ҫ�����Ϸ����res[j-1]+��ǰ��ֵ
//                else if (j == 0)
//                    res[j] += triangle[i][j];
//                else
//                    res[j] =triangle[i][j]+min(res[j],res[j-1]);
//            }
//        }
//        return *min_element(res.begin(),res.end());//��min_elementֱ�ӷ�����СԪ��
//    }
//};
//int main()
//{
//    vector<vector<int>>test = { {2},{3,4},{6,5,7} };
//    Solution a;
//    cout<< a.minimumTotal(test);
//}