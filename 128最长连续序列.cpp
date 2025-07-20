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
            if (nums[i] == res[prev] + 1)//�������������
            {
                res.push_back(nums[i]);//������ʱ������
                prev++;   //res��������ǰһλ
                if (res.size() > max_len) max_len = res.size();//���res���ȳ�����ǰ��󳤶Ⱦ͸���
            }
            else if (nums[i] == res[prev])//�����ȣ��۲���һ�����ǲ����ܺ͵�ǰ��������
            {
                continue;
            }
            else //���������
            {
                res.clear();//�����ʱ����
                res.push_back(nums[i]);//���뵱ǰ����һ����
                prev = 0; //res��������
            }
        }
        return max_len;
    }
};