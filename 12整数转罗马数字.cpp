//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//class Solution1 {
//public:
//    string intToRoman(int num) {
//        // 定义一个数组存储整数与对应的罗马数字符号
//        pair<int, string> map[] = {
//            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
//            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
//            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"},
//        };
//
//        string res;  // 存储转换后的罗马数字字符串
//
//        // 遍历数组，从大到小匹配整数值
//        for (const auto& p : map) {
//            int val = p.first;   // 当前数值
//            string str = p.second;  // 对应的罗马数字字符串
//
//            // 尽可能多地使用当前数值表示 num
//            while (num >= val) {
//                num -= val;  // 减去对应的数值
//                res += str;  // 追加对应的罗马数字
//            }
//
//            // 如果 num 变为 0，提前结束
//            if (num == 0) break;
//        }
//
//        return res;
//    }
// };
//模拟

/*const string thousands[] = { "", "M", "MM", "MMM" };
const string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
const string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
const string ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

class Solution2 {
public:
    string intToRoman(int num) {
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
    }
};*///硬除法计算，将千，百，十，个位各自所有的可能按序列举出来，然后直接计算各位对应的数字对应的字符串再相加即可，适用于范围固定的情况（1-3999）


//class Solution3 {
//public:
//    string intToRoman(int num)
//    {
//        string res;
//        while (num != 0)
//        {
//            if (num >= 1000)
//            {
//                num -= 1000;
//                res += "M";
//            }
//            else if (num >= 900)
//            {
//                num -= 1000;
//                res += "CM";
//            }
//            else if(num>=500)
//            {
//                num -= 1000;
//                res += "D";
//            }
//            else if (num >= 400)
//            {
//                num -= 400;
//                res += "CD";
//            }
//            else if (num >= 100)
//            {
//                num -= 100;
//                res += "D";
//            }
//            else if (num >= 90)
//            {
//                num -= 90;
//                res += "XC";
//            }
//            else if (num >= 50)
//            {
//                num -= 50;
//                res += "L";
//            }
//            else if (num >= 40)
//            {
//                num -= 40;
//                res += "XL";
//            }
//            else if (num >= 10)
//            {
//                num -= 10;
//                res += "X";
//            }
//            else if (num >= 9)
//            {
//                num -= 9;
//                res += "IX";
//            }
//            else if (num >= 5)
//            {
//                num -= 5;
//                res += "X";
//            }
//            else if (num >= 4)
//            {
//                num -= 4;
//                res += "IV";
//            }
//            else if (num >= 1)
//            {
//                num -= 1;
//                res += "I";
//            }
//        }
//        return res;
//    }
//};

