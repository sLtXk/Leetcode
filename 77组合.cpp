//#include<vector>
//#include<iostream>
//using namespace std;
//
//class Solution {
//public:
//    vector<vector<int>> combine(int n, int k) {
//        vector<int>path;
//        vector<vector<int>>res;
//        backtrace(n, k, 1, path, res);
//        return res;
//    }
//
//    void backtrace(int n, int k, int start,vector<int>& path, vector<vector<int>>res) {
//        if (path.size() == k) {
//            res.push_back(path);
//            return;
//        }
//        for (int i = start; i <= n; i++) {//这里求的是组合而不是排列，所以不用从头开始遍历，只需向后寻找元素即可
//            path.push_back(i);//选择当前元素
//            backtrace(n, k, i + 1, path, res);//递归选择下一个元素，这里传递i+1就避免了选取相同元素
//            path.pop_back();//得到一个结果后撤销上一轮的选择
//        }
//    }
//};