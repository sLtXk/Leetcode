//#include<iostream>
//#include<unordered_set>
//using namespace std;
//
//class Solution {
//public:
//    bool isHappy(int n) 
//    {
//        int sum = 0;//��¼ÿ��ƽ����
//        unordered_set<int>st;
//        while (n!= 1)//���ƽ����Ϊ1ֱ���˳�
//        {
//            while (n != 0)
//            {
//                int tmp = n % 10;
//                sum += tmp * tmp;
//                n /= 10;
//            }
//            if (st.count(sum)) break;//�����ǰ���ֵ�ƽ�����Ѿ����ֹ���˵��һ����ѭ����ȥ��û����ʹƽ����Ϊ1�����֣�ֱ���˳�
//            st.insert(sum);
//            n = sum;//n����Ϊ��һ�ֵ�ƽ����
//            sum = 0;//ƽ���͹���
//        }
//        return n==1;//���ͨ��while�˳�ѭ������ƽ����Ϊ1�����棬���ͨ��break�˳���˵�����������������ؼ�
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