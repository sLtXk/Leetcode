//#include<iostream>
//#include<stack>
//#include<string>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int evalRPN(vector<string>& tokens) 
//    {
//        int res = 0;
//        stack<int>stk;
//        for (string const& token : tokens)
//        {
//            int num1, num2 = 0;
//            if (token == "+")
//            {
//                num1 = stk.top(); stk.pop();
//                num2 = stk.top(); stk.pop();
//                stk.push(num1 + num2);
//            }
//            else if (token == "-")
//            {
//                num1 = stk.top(); stk.pop();
//                num2 = stk.top(); stk.pop();
//                stk.push(num2 - num1);
//            }
//            else if (token == "*")
//            {
//                num1 = stk.top(); stk.pop();
//                num2 = stk.top(); stk.pop();
//                stk.push(num1 * num2);
//            }
//            else if (token == "/")
//            {
//                num1 = stk.top(); stk.pop();
//                num2 = stk.top(); stk.pop();
//                stk.push(num2 / num1);
//            }
//            else stk.push(stoi(token));
//        }
//        return stk.top();
//    }
//};
//int main()
//{
//    vector <string>tokens = { {"4"} ,{"13"},{"5"},{"/"},{"+"} };
//    Solution a;
//    cout << a.evalRPN(tokens);
//}