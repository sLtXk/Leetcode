//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//class Solution {
//public:
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//        int totalGas = 0, totalCost = 0;
//        int curGas = 0, start = 0;
//
//        for (int i = 0; i < gas.size(); i++) {
//            totalGas += gas[i];
//            totalCost += cost[i];
//            curGas += gas[i] - cost[i];
//
//            // �����ǰ����С��0��˵�� start~i ֮�䶼��������Ϊ���
//            if (curGas < 0) {
//                start = i + 1;  // �������
//                curGas = 0;  // ��յ�ǰ����
//            }
//        }
//
//        return (totalGas < totalCost) ? -1 : start;
//    }
//};
/*Ϊʲô����ֱ������start֮�������������Ϊ������ܴ�i����������˵���ӵ����Ǵ���
���ĵģ��������start������������������Ȼ˵��i��start��λ����һ���ּӵ��Ϳ϶�С
�����ĵ��ͣ������һ�ο϶�������Ϊ��㡣
Ϊʲô���ÿ���ѭ��ʱ0-start-1�Ĳ��֣���ΪֻҪ���������������ģ�����Ķ��������
���϶����ܲ�ȫǰ��Ĳ��ֵ�����������ֻ��Ҫ�ڷ���ʱ�ж��������ǲ��Ǵ���������������*/
//int main()
//{
//    vector<int>gas = { 2,3,4}, cost = { 3,4,3 };
//    Solution a;
//    cout << a.canCompleteCircuit(gas, cost);
//}