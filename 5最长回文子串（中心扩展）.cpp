//#include<iostream>
//#include<string>
//using namespace std;
//
//string expandaroundcenter(const string& s, int left, int right)
//{
//    int n = s.size();
//    while (left >= 0 && right < n&&s[left]==s[right])
//    {
//        left--;
//        right++;
//    }
//    return s.substr(left+1, right-1 - (left + 1)+1);
//}
//
//class Solution {
//public:
//    string longestPalindrome(string s) {
//        string maxlen="";
//        for (int i = 0; i < s.size() - 1; i++)
//        {
//            string odd = expandaroundcenter(s, i, i);//�������Ȼ��Ĵ�
//            if (odd.size() > maxlen.size()) maxlen = odd;
//            string even = expandaroundcenter(s, i, i + 1);//ż�����Ȼ��Ĵ�
//            if (even.size() > maxlen.size()) maxlen = even;
//        }
//        return maxlen;
//    }
//};
//
//int main() {
//    string s = "a";
//    Solution a;
//    cout << "������Ӵ�: " << a.longestPalindrome(s) << std::endl;
//    return 0;
//}