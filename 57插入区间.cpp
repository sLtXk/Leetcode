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
//        while (i < n && intervals[i][0] < newInterval[0]) i++;//找到一个比区间头比所插区间大的位置
//        // 插入新区间
//        intervals.insert(intervals.begin() + i, newInterval);
//        return merge(intervals);//使用56的merge函数但是不需要排序
//    }
//    vector<vector<int>> merge(vector<vector<int>>& intervals)
//    {
//        if (intervals.size() == 1) return intervals;
//        vector<vector<int>>res;
//        for (const vector<int>interval : intervals)//区间只有两个元素，对应interval[0]和[1]
//        {
//            if (res.size() == 0 || interval[0] > res.back()[1])//如果res中还没有存区间，或者当前区间的头比之前区间的尾大
//                res.push_back(interval);//直接加入到res中
//            else //否则说明当前区间的头小于之前区间的尾，就可以直接合并了
//                res.back()[1] = max(interval[1], res.back()[1]);
//        }
//        return res;
//    }
//};//运用56的函数，先插入后合并，因为这题是有序区间就不需要排序了
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
//            if (interval[0] > newInterval[1])//如果当前区间比所插区间大
//            {
//                if (!occupied[0]) //如果区间没有被插入过
//                {
//                    res.push_back(newInterval);//直接插入
//                    occupied.flip();//标记为插入过
//                }
//                res.push_back(interval);//将当前区间插入
//            }
//            else if (interval[1] < newInterval[0])//如果当前区间比所插区间小
//                res.push_back(interval);//直接插入
//            else//如果有当前区间和所插区间有重叠部分
//            {
//                newInterval[0] = min(interval[0], newInterval[0]);
//                newInterval[1] = max(interval[1], newInterval[1]);
//            }//区间左端取两者之间最小，右端取最大，与intervals中多个区间重叠的话就会多次合并，直到没有重叠再进行区间的插入
//        }
//        if (!occupied[0])res.push_back(newInterval);
//        /*如果直到最后都没有插入，有两种可能：1.newInterval大于所有区间
//         2.newInterval与最后一个区间合并后循环结束 这两种情况都需要将newInterval插入进去*/
//        return res;
//    }
//};