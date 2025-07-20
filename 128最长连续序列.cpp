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
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        vector<int>res = { nums[0] };
        int prev = 0, max_len = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == res[prev] + 1)//如果是连续序列
            {
                res.push_back(nums[i]);//加入临时数组中
                prev++;   //res的索引向前一位
                if (res.size() > max_len) max_len = res.size();//如果res长度长于先前最大长度就更新
            }
            else if (nums[i] == res[prev])//如果相等，观察下一数字是不是能和当前数字连续
            {
                continue;
            }
            else //如果不连续
            {
                res.clear();//清空临时数组
                res.push_back(nums[i]);//加入当前的这一个数
                prev = 0; //res索引归零
            }
        }
        return max_len;
    }
};