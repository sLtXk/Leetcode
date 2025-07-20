//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//class Solution {
//public:
//    string reverseWords(string s)
//    {
//        vector<string>strs;
//        string res;
//        int front = 0, back = 0, n = s.size();//单词头和单词尾
//        while (back < n)
//        {
//            if (s[back] != ' ')
//            {
//                back++;//单词尾向前
//            }
//            else if (s[back] == ' ' && back - front == 0)
//            {
//                front++;
//                back++;
//            }//遇到空格且无单词存在，直接前进
//            else if (s[back] == ' ' && back - front > 0)//如果有单词存在，且遇到了空格，截断单词并返回到strs中
//            {
//                strs.emplace_back(s.substr(front, back - front));//back处已经是空格了，所以当前长度是back-front
//                front = back;//front移至当前位置
//            }
//        }
//        if (back - front > 0) strs.emplace_back(s.substr(front, back - front));//最后如果有单词会直接跳出循环,将最后一个单词补上
//        for (int i = strs.size() - 1; i >= 1; i--)
//        {
//            res += strs[i];
//            res += ' ';
//        }
//        res += strs[0];//不能有多余空格，单独补上最后一个单词
//        return res;
//    }
//};
//
//int main()
//{
//    string a = "   the sky    is blue";
//    Solution b;
//    string d = b.reverseWords(a);
//    for (char c : d)
//    {
//        cout << c;
//    }
//}