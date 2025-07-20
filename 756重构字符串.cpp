//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//#include<queue>
//#include<stack>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//    string reorganizeString(string s) {
//        // ͳ��ÿ���ַ��ĳ��ִ����������ϣ�� map
//        unordered_map<char, int> map;
//        for (char a : s)
//            map[a]++;
//
//        // ����һ�����ѣ��洢ÿ���ַ�������ִ�����pair����Ĭ�ϰ���һ��Ԫ�ؽ�����������������pairʱ�ȷ���������ַ�
//        priority_queue<pair<int, char>> max_heap;
//        for (auto& p : map) {
//            // ���ĳ���ַ���Ƶ�ʳ��� (���ַ��� + 1) / 2�����޷�������֯�����ؿ��ַ���
//            if (p.second > (s.size() + 1) / 2) return "";
//            max_heap.push({ p.second, p.first }); // ���ַ�����Ƶ����Ϊ pair ѹ�����
//        }
//
//        string res = ""; // ����ַ���
//
//        // ����������������Ԫ��ʱ��ȡ��Ƶ����ߵ������ַ�
//        while (max_heap.size() >= 2) {
//            auto top1 = max_heap.top(); max_heap.pop();
//            int count1 = top1.first;  // ��һ���ַ���Ƶ��
//            char ch1 = top1.second;  // ��һ���ַ�
//            auto top2 = max_heap.top(); max_heap.pop();
//            int count2 = top2.first; // �ڶ����ַ���Ƶ��
//            char ch2 = top2.second; // �ڶ����ַ�
//
//            // �������ַ�����������ַ�����
//            res += ch1;
//            res += ch2;
//
//            // ����ַ���ʣ��������� 0����������ѹ�����
//            if (--count1 > 0) max_heap.push({ count1, ch1 });
//            if (--count2 > 0) max_heap.push({ count2, ch2 });
//        }
//
//        // ������л���һ���ַ���ֱ�ӽ�����ӵ�����ַ���ĩβ
//        if (!max_heap.empty()) {
//            res += max_heap.top().second;
//        }
//
//        return res; // ���ؽ���ַ���
//    }
//}; 
//
//int main()
//{
//    string y = "brbsf";
//    Solution a;
//    string res = a.reorganizeString(y);
//    cout << res;
//}