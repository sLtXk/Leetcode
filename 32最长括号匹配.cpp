//#include<stack>
//#include<iostream>
//using namespace std;
//
//
//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        stack<int>stk;//记录入栈的左括号的下标
//        int maxlen = 0;
//        stk.push(-1);//初始基准,因为s[i]到s[j]长度是i-j+1，所以用-1天然表示长度
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] == '(') stk.push(i);
//            else {
//                stk.pop();//如果是右括号就直接弹出
//                if (stk.empty()) stk.push(i);//弹出后是如果栈是空的，说明是单一个右括号，不是有效括号,作为新的基准
//                else maxlen = max(maxlen, i - stk.top());//如果有基准，最大长度更新
//            }
//        }
//        //将非有效的右括号作为下一对有效括号的基准更新
//        return maxlen;
//    }
//};//解法1，栈
//
//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        int left = 0, right = 0;//记录左右括号数量
//        int maxlen = 0;
//        for (char& ch : s) {//从左到右计数
//            if (ch == '(') left++;
//            else right++;
//
//            if (right > left) left = right = 0;//从左到右计数，右括号的数量不可以大于左括号，否则必然无效，计数清零
//            else if (left == right) maxlen = max(maxlen, left * 2);//如果左右括号数量相等，长度即为乘2
//            //从左到右计数左括号可以多于右括号
//        }
//        left = right = 0;
//        for (int i = s.size() - 1; i >= 0; i--) {
//            if (s[i] == ')') right++;
//            else left++;
//
//            if (left > right) left = right = 0;//从右到左计数，左括号的数量不可以大于右括号，否则必然无效，计数清零
//            else if (left == right) maxlen = max(maxlen, left * 2);//如果左右括号数量相等，长度即为乘2
//            //从右到左计数右括号可以多于左括号
//        }
//        return maxlen;
//    }
//};