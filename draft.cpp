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
        // 定义一个数组存储整数与对应的罗马数字符号
        pair<int, string> map[] = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"},
        };

        string res;  // 存储转换后的罗马数字字符串

        // 遍历数组，从大到小匹配整数值
        for (const auto& p : map) {
            int val = p.first;   // 当前数值
            string str = p.second;  // 对应的罗马数字字符串

            // 尽可能多地使用当前数值表示 num
            while (num >= val) {
                num -= val;  // 减去对应的数值
                res += str;  // 追加对应的罗马数字
            }

            // 如果 num 变为 0，提前结束
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