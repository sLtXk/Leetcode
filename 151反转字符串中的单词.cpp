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
//        int front = 0, back = 0, n = s.size();//����ͷ�͵���β
//        while (back < n)
//        {
//            if (s[back] != ' ')
//            {
//                back++;//����β��ǰ
//            }
//            else if (s[back] == ' ' && back - front == 0)
//            {
//                front++;
//                back++;
//            }//�����ո����޵��ʴ��ڣ�ֱ��ǰ��
//            else if (s[back] == ' ' && back - front > 0)//����е��ʴ��ڣ��������˿ո񣬽ضϵ��ʲ����ص�strs��
//            {
//                strs.emplace_back(s.substr(front, back - front));//back���Ѿ��ǿո��ˣ����Ե�ǰ������back-front
//                front = back;//front������ǰλ��
//            }
//        }
//        if (back - front > 0) strs.emplace_back(s.substr(front, back - front));//�������е��ʻ�ֱ������ѭ��,�����һ�����ʲ���
//        for (int i = strs.size() - 1; i >= 1; i--)
//        {
//            res += strs[i];
//            res += ' ';
//        }
//        res += strs[0];//�����ж���ո񣬵����������һ������
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