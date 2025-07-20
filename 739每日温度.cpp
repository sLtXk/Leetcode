#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp)
    {
        int n = tmp.size();
        vector<int>ans(n);
        stack<int>stk;
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && tmp[i] > stk.top())
            {
                int pre = stk.top();
                ans[pre] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};//µ¥µ÷Õ»