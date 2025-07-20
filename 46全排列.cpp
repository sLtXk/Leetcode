//#include<vector>
//#include<iostream>
//using namespace std;
//
//class Solution {
//public:
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<vector<int>>res;
//        vector<int>path;
//        vector<bool>used(nums.size(), false);//ȫ���в�ͬ����ϣ�ÿһ�ζ�Ҫ��ͷ��ʼѰ�����֣���Ҫһ����������������Ƿ�ʹ�ù�
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
//            used[i] = false;//�ݹ��������Ҫ���ص�ǰѡȡ��Ԫ�أ����Ϊδʹ��
//            path.pop_back();//����ѡ��
//        }
//    }
//};