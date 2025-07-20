//#include<vector>
//#include<iostream>
//using namespace std;
//
//class Solution {
//public:
//    vector<vector<int>> subsets(vector<int>& nums) {
//        vector<vector<int>>res;
//        vector<int>path;
//        backtrack(nums, 0, res, path);
//        return res;
//    }
//
//    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res, vector<int>& path) {
//        res.push_back(path);//每一个节点都是一个解，加入结果
//        for (int i = start; i < nums.size(); i++) {
//            path.push_back(nums[i]);//选择当前路径
//            backtrack(nums, i + 1, res, path);//递归，下一个数字也重复上述过程
//            path.pop_back();//撤销当前路径，选择其他路径
//        }
//    }
//};
///*
//回溯问题的模板
//void backtrack(参数) {
//    if (终止条件) {
//        存储结果;
//        return;
//    }
//    for (所有选择) {
//        做选择;
//        回溯;
//        撤销选择;
//    }
//}
//*/
//int main() {
//    vector<int>nums = { 1,2,3,4,5 };
//    Solution a;
//    a.subsets(nums);
//}