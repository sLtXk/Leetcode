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
//            if (points[i][0] < tmp[1])//两个区间有交集可用一只箭
//            {
//                tmp[0] = points[i][0];//交集左端点为当前区间的左端点（因为已经排序了）
//                tmp[1] = min(tmp[1], points[i][1]);//交集右端点为两个区间右端点较小的那一个
//            }
//            else//没有交集则更新tmp为当前区间
//            {
//                tmp[0] = points[i][0];
//                tmp[1] = points[i][1];
//                res++;//需要多一只箭才能射掉气球
//            }
//        }
//        return res;
//    }
//};//自己的方法
//
//class Solution {
//public:
//    int findMinArrowShots(vector<vector<int>>& points) {
//        if (points.empty()) return 0;
//
//        // 按右端点排序，确保尽可能早地射掉最多的气球
//        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
//            return a[1] < b[1];
//            });
//
//        int res = 1;
//        int end = points[0][1]; // 记录当前射出的箭的终点
//        for (const auto& p : points) {
//            if (p[0] > end) { // 当前气球左端点超过了之前的箭能射到的范围
//                res++;
//                end = p[1]; // 更新新箭的终点
//            }
//        }
//        return res;
//    }
//};//官答贪心算法
