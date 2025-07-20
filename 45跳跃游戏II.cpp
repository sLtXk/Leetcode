//#include<iostream>
//#include<vector>
//#include<string>
//#include<unordered_set>
//using namespace std;
//
//class Solution {
//public:
//    int jump(vector<int>& nums) {
//        int n = nums.size();
//        if (n == 1) return 0;
//
//        int step = 0, curEnd = 0, maxpos = 0;
//
//        for (int i = 0; i < n - 1; i++) {
//            maxpos = max(maxpos, i + nums[i]); // 计算最远可达位置
//
//            if (i == curEnd) { // 需要跳跃
//                step++;
//                curEnd = maxpos;
//                if (curEnd >= n - 1) return step; // 提前返回
//            }
//        }
//        return step;
//    }
//};
//
//int main()
//{
//    vector<int>nums{ 2,3,0,1,4 };
//    Solution a;
//    cout << a.jump(nums);
//}