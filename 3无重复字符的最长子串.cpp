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
//        unordered_map<char, int> hash;  // ��¼�ַ���������λ��
//        int maxLen = 0;
//        int left = 0;  // �������ڵ���߽�
//
//        for (int right = 0; right < s.size(); ++right) {
//            if (hash.find(s[right]) != hash.end()) 
//            {
//                // ����ַ��ظ��ˣ�������߽磨ȡ���ֵ�Ա�֤��߽粻����ˣ�
//                left = max(left, hash[s[right]] + 1);
//            }
//            hash[s[right]] = right;  // �����ַ���������λ��
//            maxLen = max(maxLen, right - left + 1);  // ���㵱ǰ����Ӵ�����
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