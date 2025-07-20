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
//    unordered_map<char, string>digitToLetter{
//        {'2',"abc"},
//        {'3',"def"},
//        {'4',"ghi"},
//        {'5',"jkl"},
//        {'6',"mno"},
//        {'7',"pqrs"},
//        {'8',"tuv"},
//        {'9',"wxyz"},
//    };
//    vector<string> letterCombinations(string digits) {
//        if (digits.size() == 0) return {};
//        string path;
//        vector<string>res;
//        backtrace(digits, path, res, 0);
//        return res;
//    }
//
//    void backtrace(string digits, string& path, vector<string>& res, int index) {
//        if (index == digits.size()) {//索引等于数字大小，说明path的长度已经满足要求了，返回对应字母组合
//            res.push_back(path);
//            return;
//        }
//        char digit = digits[index];//当前数字
//        string& letter = digitToLetter[digit];//选择当前数字对应的字母列表
//        for (char& ch : letter) {//遍历列表中的数字
//            path += ch;
//            backtrace(digits, path, res, index + 1);
//            path.pop_back();//撤销选择
//        }
//    }
//}; public:
//    unordered_map<char, string>digitToLetter{
//        {'2',"abc"},
//        {'3',"def"},
//        {'4',"ghi"},
//        {'5',"jkl"},
//        {'6',"mno"},
//        {'7',"pqrs"},
//        {'8',"tuv"},
//        {'9',"wxyz"},        
//    };
//    vector<string> letterCombinations(string digits) {
//        string path;
//        vector<string>res;
//        backtrace(digits, path, res, 0);
//    }
//
//    void backtrace(string digits, string& path, vector<string>&res,int index) {
//        if (index==digits.size()) {//索引等于数字大小，说明path的长度已经满足要求了，返回对应字母组合
//            res.push_back(path);
//            return;
//        }
//        char digit = digits[index];//当前数字
//        string &letter = digitToLetter[digit];//选择当前数字对应的字母列表
//        for (char& ch : letter) {//遍历列表中的数字
//            path += ch;
//            backtrace(digits, path, res, index + 1);
//            path.pop_back();//撤销选择
//        }
//    }
//};