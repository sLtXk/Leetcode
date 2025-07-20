//#include<vector>
//#include<iostream>
//using namespace std;
//
//class Solution {
//public:
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<vector<int>>res;
//        vector<int>path;
//        vector<bool>used(nums.size(), false);//全排列不同于组合，每一次都要从头开始寻找数字，需要一个数组来标记数字是否使用过
//        backtrace(nums, res, path, used);
//        return res;
//    }
//
//    void backtrace(vector<int>& nums, vector<vector<int>>&res, vector<int>&path,vector<bool>&used) {
//        if (path.size() == nums.size()) {
//            res.push_back(path);
//            return;
//        }
//        for (int i = 0; i < nums.size(); i++) {
//            if (used[i] == true) continue;
//            used[i] = true;
//            path.push_back(nums[i]);
//            backtrace(nums, res, path, used);
//            used[i] = false;//递归结束，需要撤回当前选取的元素，标记为未使用
//            path.pop_back();//撤销选择
//        }
//    }
//};