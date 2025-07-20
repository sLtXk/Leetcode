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
//    string reorganizeString(string s) {
//        // 统计每个字符的出现次数，存入哈希表 map
//        unordered_map<char, int> map;
//        for (char a : s)
//            map[a]++;
//
//        // 定义一个最大堆，存储每个字符及其出现次数（pair），默认按第一个元素降序排序，所以这里用pair时先放整数后放字符
//        priority_queue<pair<int, char>> max_heap;
//        for (auto& p : map) {
//            // 如果某个字符的频率超过 (总字符数 + 1) / 2，则无法重新组织，返回空字符串
//            if (p.second > (s.size() + 1) / 2) return "";
//            max_heap.push({ p.second, p.first }); // 将字符及其频率作为 pair 压入堆中
//        }
//
//        string res = ""; // 结果字符串
//
//        // 当堆中有至少两个元素时，取出频率最高的两个字符
//        while (max_heap.size() >= 2) {
//            auto top1 = max_heap.top(); max_heap.pop();
//            int count1 = top1.first;  // 第一个字符的频率
//            char ch1 = top1.second;  // 第一个字符
//            auto top2 = max_heap.top(); max_heap.pop();
//            int count2 = top2.first; // 第二个字符的频率
//            char ch2 = top2.second; // 第二个字符
//
//            // 将两个字符交替插入结果字符串中
//            res += ch1;
//            res += ch2;
//
//            // 如果字符的剩余次数大于 0，则将其重新压入堆中
//            if (--count1 > 0) max_heap.push({ count1, ch1 });
//            if (--count2 > 0) max_heap.push({ count2, ch2 });
//        }
//
//        // 如果堆中还有一个字符，直接将其添加到结果字符串末尾
//        if (!max_heap.empty()) {
//            res += max_heap.top().second;
//        }
//
//        return res; // 返回结果字符串
//    }
//}; 
//
//int main()
//{
//    string y = "brbsf";
//    Solution a;
//    string res = a.reorganizeString(y);
//    cout << res;
//}