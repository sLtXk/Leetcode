#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include<queue>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, cost = INT_MAX;
        for (int price : prices)
        {
            cost = min(price, cost);
            profit = max(profit, price - cost);
        }
    }
};