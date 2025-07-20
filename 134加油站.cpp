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
//            // 如果当前油量小于0，说明 start~i 之间都不可能作为起点
//            if (curGas < 0) {
//                start = i + 1;  // 更新起点
//                curGas = 0;  // 清空当前油量
//            }
//        }
//
//        return (totalGas < totalCost) ? -1 : start;
//    }
//};
/*为什么可以直接跳到start之后继续遍历？因为如果你能从i处启动，就说明加的油是大于
消耗的，如果你在start处发现油量不够，必然说明i到start的位置这一部分加的油肯定小
于消耗的油，因此这一段肯定不能作为起点。
为什么不用考虑循环时0-start-1的部分？因为只要总油量大于总消耗，后面的多出来的油
量肯定就能补全前面的部分的油量，我们只需要在返回时判断总油量是不是大于总消耗量即可*/
//int main()
//{
//    vector<int>gas = { 2,3,4}, cost = { 3,4,3 };
//    Solution a;
//    cout << a.canCompleteCircuit(gas, cost);
//}