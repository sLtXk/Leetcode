#include<iostream>
#include<vector>
#include<deque>
#include<unordered_map>
#include<list>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        // ����һ������洢�������Ӧ���������ַ���
        pair<int, string> map[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"},
        };

        string res;  // �洢ת��������������ַ���

        // �������飬�Ӵ�Сƥ������ֵ
        for (const auto& p : map) {
            int val = p.first;   // ��ǰ��ֵ
            string str = p.second;  // ��Ӧ�����������ַ���

            // �����ܶ��ʹ�õ�ǰ��ֵ��ʾ num
            while (num >= val) {
                num -= val;  // ��ȥ��Ӧ����ֵ
                res += str;  // ׷�Ӷ�Ӧ����������
            }

            // ��� num ��Ϊ 0����ǰ����
            if (num == 0) break;
        }

        return res;
    }
};

int main()
{
    vector<int>ratings{ 1,0,2 };
    Solution a;
    cout << a.candy(ratings) << endl;
}