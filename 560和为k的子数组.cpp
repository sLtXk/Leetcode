//#include<vector>
//#include<algorithm>
//
//using namespace std;
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int res = 0;
//        for (int i = 0; i < nums.size(); i++) {
//            int sum = 0;
//            sum += nums[i];
//            if (sum == k) res++;
//            for (int j = i + 1; j < nums.size(); j++) {
//                sum += nums[j];
//                if (sum == k) res++;
//            }
//        }
//        return res;
//    }
//};//枚举，复杂度O(n^2)
//
//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        unordered_map<int, int>preSum;//哈希表，键为前缀和，值为出现次数
//        preSum[0] = 1;//一开始前缀和为0的出现次数为1次，因为数组还没开始遍历默认为0
//        int res = 0,sum=0;
//        for (int i = 0; i < nums.size(); i++) {
//            sum += nums[i];
//            if (preSum.count(sum - k)) {
//                res += preSum[sum - k];//子数组的个数就等于前缀和为sum-k的出现次数
//            }//如果哈希表中能找到前缀和为当前的sum减去k，说明在前缀和sum-k到前缀和为sum的中间这段子出数组和为k，因为sum-(sum-k)=k
//            preSum[sum]++;//记录当前前缀和出现次数
//        }
//        return res;
//    }
//};
//
//int main()
//{
//    vector<int>nums = { 1,2,3 };
//    int k = 3;
//    Solution a;
//    cout << a.subarraySum(nums, k);
//}