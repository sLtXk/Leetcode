//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//#include<bitset>
//using namespace std;
//vector<vector<int>> merge(vector<vector<int>>& intervals)
//{
//    if (intervals.size() == 1) return intervals;
//    sort(intervals.begin(), intervals.end());//对于多维数组，sort根据字典序由小到大进行排序，先比较区间头interval[0]的大小，再比较区间尾interval[1]的大小
//    vector<vector<int>>res;
//    for (const vector<int>interval : intervals)//区间只有两个元素，对应interval[0]和[1]
//    {
//        if (res.size() == 0 || interval[0] > res.back()[1])//如果res中还没有存区间，或者当前区间的头比之前区间的尾大
//            res.push_back(interval);//直接加入到res中
//        else //否则说明当前区间的头小于之前区间的尾，就可以直接合并了
//            res.back()[1] = max(interval[1], res.back()[1]);
//    }
//    return res;
//}