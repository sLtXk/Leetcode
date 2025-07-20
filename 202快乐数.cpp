//#include<iostream>
//#include<unordered_set>
//using namespace std;
//
//class Solution {
//public:
//    bool isHappy(int n) 
//    {
//        int sum = 0;//记录每组平方和
//        unordered_set<int>st;
//        while (n!= 1)//如果平方和为1直接退出
//        {
//            while (n != 0)
//            {
//                int tmp = n % 10;
//                sum += tmp * tmp;
//                n /= 10;
//            }
//            if (st.count(sum)) break;//如果当前数字的平方和已经出现过，说明一大轮循环过去后没有能使平方和为1的数字，直接退出
//            st.insert(sum);
//            n = sum;//n更新为这一轮的平方和
//            sum = 0;//平方和归零
//        }
//        return n==1;//如果通过while退出循环，则平方和为1返回真，如果通过break退出，说明不满足条件，返回假
//    }
//};
//
//
//int main()
//{
//    int n = 2;
//    Solution a;
//    cout << a.isHappy(n);
//}