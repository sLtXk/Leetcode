//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p) {
//        vector<int>cnt_window(26, 0), cnt_p(26, 0);//记录s中滑动窗口的词频和p的词频
//        for (char& ch : p) cnt_p[ch - 'a'] ++; //初始化p的词频
//        vector<int> res;
//        int len = p.size();
//        for (int right = 0; right < s.size(); right++) {
//            cnt_window[s[right] - 'a']++;
//            if (right >= len) {//如果当前窗口长度比p的长度长了（取等于是因为right是索引，right=len时窗口长度是right+1）
//                cnt_window[s[right - len] - 'a']--;//窗口左侧收缩
//            }
//            if (cnt_window == cnt_p) res.push_back(right - len + 1); // 当前窗口是异位词,返回窗口左边界
//        }
//        return res;
//
//    }
//};
//
//int main() {
//    string str = "cbaebabacd";
//    string p = "abc";
//    Solution a;
//    vector<int>res=a.findAnagrams(str,p);
//    for (int num : res) cout << num << " ";
//    cout << endl;
//}