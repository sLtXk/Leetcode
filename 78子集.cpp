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
//        res.push_back(path);//ÿһ���ڵ㶼��һ���⣬������
//        for (int i = start; i < nums.size(); i++) {
//            path.push_back(nums[i]);//ѡ��ǰ·��
//            backtrack(nums, i + 1, res, path);//�ݹ飬��һ������Ҳ�ظ���������
//            path.pop_back();//������ǰ·����ѡ������·��
//        }
//    }
//};
///*
//���������ģ��
//void backtrack(����) {
//    if (��ֹ����) {
//        �洢���;
//        return;
//    }
//    for (����ѡ��) {
//        ��ѡ��;
//        ����;
//        ����ѡ��;
//    }
//}
//*/
//int main() {
//    vector<int>nums = { 1,2,3,4,5 };
//    Solution a;
//    a.subsets(nums);
//}