//#include<iostream>
//#include<vector>
//#include<string>
//#include<unordered_set>
//using namespace std;
//class Solution {
//public:
//    vector<string> buildArray(vector<int>& target, int n) {
//        vector<string> res;
//        int j = 1; // j 遍历从 1 到 n 的数
//        for (int i = 0; i < target.size(); i++) {
//            while (j < target[i]) { // 说明 target[i] 还没出现，先执行 "Push" -> "Pop"
//                res.push_back("Push");
//                res.push_back("Pop");
//                j++; // 继续下一个数字
//            }
//            res.push_back("Push"); // 现在 j == target[i]，成功入栈
//            j++; // 继续处理下一个数
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