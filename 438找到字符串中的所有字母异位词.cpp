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
//        vector<int>cnt_window(26, 0), cnt_p(26, 0);//��¼s�л������ڵĴ�Ƶ��p�Ĵ�Ƶ
//        for (char& ch : p) cnt_p[ch - 'a'] ++; //��ʼ��p�Ĵ�Ƶ
//        vector<int> res;
//        int len = p.size();
//        for (int right = 0; right < s.size(); right++) {
//            cnt_window[s[right] - 'a']++;
//            if (right >= len) {//�����ǰ���ڳ��ȱ�p�ĳ��ȳ��ˣ�ȡ��������Ϊright��������right=lenʱ���ڳ�����right+1��
//                cnt_window[s[right - len] - 'a']--;//�����������
//            }
//            if (cnt_window == cnt_p) res.push_back(right - len + 1); // ��ǰ��������λ��,���ش�����߽�
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