//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        unordered_map<char, int> hash;  // 记录字符的最后出现位置
//        int maxLen = 0;
//        int left = 0;  // 滑动窗口的左边界
//
//        for (int right = 0; right < s.size(); ++right) {
//            if (hash.find(s[right]) != hash.end()) 
//            {
//                // 如果字符重复了，更新左边界（取最大值以保证左边界不会回退）
//                left = max(left, hash[s[right]] + 1);
//            }
//            hash[s[right]] = right;  // 更新字符的最后出现位置
//            maxLen = max(maxLen, right - left + 1);  // 计算当前最大子串长度
//        }
//
//        return maxLen;
//    }
//};
//int main()
//{
//    string s = "tmmzuxt";
//    Solution a;
//    cout << a.lengthOfLongestSubstring(s);
//}