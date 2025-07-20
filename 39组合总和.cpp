//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<unordered_set>
//#include<string>
//#include<algorithm>
//#include<queue>
//using namespace std;
//
//class Solution {
//public:
//
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        vector<int>path;
//        vector<vector<int>>res;
//        sort(candidates.begin(), candidates.end());//排序方便剪枝
//        int curSum = 0;
//        int start = 0;
//        backtrack(candidates, res, path, target, curSum,start);
//        return res;
//    }
//
//    void backtrack(vector<int>& candidates,vector<vector<int>>& res, vector<int>&path,int target,int curSum,int start) {
//        if (curSum == target) {
//            res.push_back(path);
//            return;
//        }
//        for (int i = start; i < candidates.size(); i++) {//这里每一次都从当前索引开始选，因为同一数字可以选任意次
//            curSum += candidates[i];
//            if (curSum > target) return;//因为是排序了的数组，所以如果总和大了就可以直接返回了
//            path.push_back(candidates[i]);
//            backtrack(candidates, res, path, target, curSum,i);
//            /* 注意这里递归中传递的是参数 i 而不是 i + 1，是为了允许同一个元素被重复选取（组合中元素可以重复使用）。
//               同时通过引入 start 参数控制每层递归从当前位置或之后开始遍历，避免产生不同顺序的重复组合（即排列）。
//               如果不引入 start，每一层都从 0 开始选，就会产生顺序不同但值相同的组合 —— 即排列而不是组合。*/
//            path.pop_back();//撤销当前选择
//            curSum -= candidates[i];//减掉当前数字
//        }
//    }
//};
//
//int main() {
//    vector<int>candidates = { 2,3,6,7 };
//    Solution a;
//    int target = 7;
//    vector<vector<int>>res=a.combinationSum(candidates, target);
//    return 0;
//}