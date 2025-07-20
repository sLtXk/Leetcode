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
//        // ����һ������洢�������Ӧ���������ַ���
//        pair<int, string> map[] = {
//            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
//            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
//            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"},
//        };
//
//        string res;  // �洢ת��������������ַ���
//
//        // �������飬�Ӵ�Сƥ������ֵ
//        for (const auto& p : map) {
//            int val = p.first;   // ��ǰ��ֵ
//            string str = p.second;  // ��Ӧ�����������ַ���
//
//            // �����ܶ��ʹ�õ�ǰ��ֵ��ʾ num
//            while (num >= val) {
//                num -= val;  // ��ȥ��Ӧ����ֵ
//                res += str;  // ׷�Ӷ�Ӧ����������
//            }
//
//            // ��� num ��Ϊ 0����ǰ����
//            if (num == 0) break;
//        }
//
//        return res;
//    }
// };
//ģ��

/*const string thousands[] = { "", "M", "MM", "MMM" };
const string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
const string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
const string ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

class Solution2 {
public:
    string intToRoman(int num) {
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
    }
};*///Ӳ�������㣬��ǧ���٣�ʮ����λ�������еĿ��ܰ����оٳ�����Ȼ��ֱ�Ӽ����λ��Ӧ�����ֶ�Ӧ���ַ�������Ӽ��ɣ������ڷ�Χ�̶��������1-3999��


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

