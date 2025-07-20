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
//        sort(candidates.begin(), candidates.end());//���򷽱��֦
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
//        for (int i = start; i < candidates.size(); i++) {//����ÿһ�ζ��ӵ�ǰ������ʼѡ����Ϊͬһ���ֿ���ѡ�����
//            curSum += candidates[i];
//            if (curSum > target) return;//��Ϊ�������˵����飬��������ܺʹ��˾Ϳ���ֱ�ӷ�����
//            path.push_back(candidates[i]);
//            backtrack(candidates, res, path, target, curSum,i);
//            /* ע������ݹ��д��ݵ��ǲ��� i ������ i + 1����Ϊ������ͬһ��Ԫ�ر��ظ�ѡȡ�������Ԫ�ؿ����ظ�ʹ�ã���
//               ͬʱͨ������ start ��������ÿ��ݹ�ӵ�ǰλ�û�֮��ʼ���������������ͬ˳����ظ���ϣ������У���
//               ��������� start��ÿһ�㶼�� 0 ��ʼѡ���ͻ����˳��ͬ��ֵ��ͬ����� ���� �����ж�������ϡ�*/
//            path.pop_back();//������ǰѡ��
//            curSum -= candidates[i];//������ǰ����
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