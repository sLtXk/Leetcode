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
//            str[row] += ch;//�ڵ�ǰ�м����ַ�
//            if (row == 0) flag = 1;//������ж��˾����¼ӣ�0�Ƕ���
//            else if (row == numRows - 1) flag = -1;//�����˾����ϼ���numRows-1�ǵף�
//            row += flag;//Z�����ƶ�
//        }
//        string res;
//        for (string& a : str)
//            res += a;    //��ÿ�����μ���
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