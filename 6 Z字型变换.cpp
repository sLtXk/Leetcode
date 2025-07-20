//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    string convert(string s, int numRows) {
//        if (s.size() < numRows) return s;
//
//        vector<string>str(numRows);
//        int row = 0, flag = 1;
//        for (char ch : s)
//        {
//            str[row] += ch;//在当前行加上字符
//            if (row == 0) flag = 1;//如果到行顶了就往下加（0是顶）
//            else if (row == numRows - 1) flag = -1;//到底了就网上减（numRows-1是底）
//            row += flag;//Z字形移动
//        }
//        string res;
//        for (string& a : str)
//            res += a;    //将每行依次加入
//        return res;
//    }
//};
//
//
//int main()
//{
//    string s = "AB";
//    Solution a;
//    string res = a.convert(s, 1);
//    for (const char& c : res)
//        cout << c;
//}