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
//        if (index == digits.size()) {//�����������ִ�С��˵��path�ĳ����Ѿ�����Ҫ���ˣ����ض�Ӧ��ĸ���
//            res.push_back(path);
//            return;
//        }
//        char digit = digits[index];//��ǰ����
//        string& letter = digitToLetter[digit];//ѡ��ǰ���ֶ�Ӧ����ĸ�б�
//        for (char& ch : letter) {//�����б��е�����
//            path += ch;
//            backtrace(digits, path, res, index + 1);
//            path.pop_back();//����ѡ��
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
//        if (index==digits.size()) {//�����������ִ�С��˵��path�ĳ����Ѿ�����Ҫ���ˣ����ض�Ӧ��ĸ���
//            res.push_back(path);
//            return;
//        }
//        char digit = digits[index];//��ǰ����
//        string &letter = digitToLetter[digit];//ѡ��ǰ���ֶ�Ӧ����ĸ�б�
//        for (char& ch : letter) {//�����б��е�����
//            path += ch;
//            backtrace(digits, path, res, index + 1);
//            path.pop_back();//����ѡ��
//        }
//    }
//};