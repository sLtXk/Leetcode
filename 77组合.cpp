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
//        for (int i = start; i <= n; i++) {//�����������϶��������У����Բ��ô�ͷ��ʼ������ֻ�����Ѱ��Ԫ�ؼ���
//            path.push_back(i);//ѡ��ǰԪ��
//            backtrace(n, k, i + 1, path, res);//�ݹ�ѡ����һ��Ԫ�أ����ﴫ��i+1�ͱ�����ѡȡ��ͬԪ��
//            path.pop_back();//�õ�һ�����������һ�ֵ�ѡ��
//        }
//    }
//};