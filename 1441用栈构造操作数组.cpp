//#include<iostream>
//#include<vector>
//#include<string>
//#include<unordered_set>
//using namespace std;
//class Solution {
//public:
//    vector<string> buildArray(vector<int>& target, int n) {
//        vector<string> res;
//        int j = 1; // j ������ 1 �� n ����
//        for (int i = 0; i < target.size(); i++) {
//            while (j < target[i]) { // ˵�� target[i] ��û���֣���ִ�� "Push" -> "Pop"
//                res.push_back("Push");
//                res.push_back("Pop");
//                j++; // ������һ������
//            }
//            res.push_back("Push"); // ���� j == target[i]���ɹ���ջ
//            j++; // ����������һ����
//        }
//        return res;
//    }
//};
//
//int main()
//{
//    int n = 3;
//    vector<int>target = { 1,2 };
//    Solution a;
//    vector<string>res = a.buildArray(target, n);
//    for (string s : res)
//        cout << s << endl;
//}