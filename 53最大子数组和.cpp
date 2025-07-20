//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//class Solution1 {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int preSum = 0, minPreSum = 0, res = INT_MIN;//分别为当前前缀和，先前的最小前缀和，和结果
//        for (int& num : nums) {
//            preSum += num;
//            res = max(res, preSum - minPreSum);//结果就等于当前答案和当前前缀和-最小前缀和的最大值
//            minPreSum = min(minPreSum, preSum);//更新最小前缀和
//        }
//        return res;
//    }
//};/*计算最大子数组和相当于找到一个最大的（当前前缀和减去先前的最小前缀和），利用了Kadane算法的思想*/
//
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int curSum = 0, maxSum = INT_MIN;//以当前数字为结尾的最大子数组和，与最大子数组和
//        for (int& num : nums) {
//            curSum = max(num, curSum + num);//本质上是在判断先前最大子数组和是否为负，如果为负不如直接选用nums[i]
//            maxSum = max(maxSum, curSum);
//        }
//        return maxSum;
//    }
//};
///*Kadane算法：“要么接着干，要么从头来”
//“当前最优 vs 全局最优”*/
//
//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int curSum = 0, maxSum = INT_MIN;
//        int start = 0, tempStart = 0, end = 0;
//
//        for (int i = 0; i < nums.size(); ++i) {
//            if (curSum + nums[i] < nums[i]) {
//                curSum = nums[i];
//                tempStart = i; // 当前元素更优，更新起始位置
//            }
//            else {
//                curSum += nums[i];
//            }
//
//            if (curSum > maxSum) {
//                maxSum = curSum;
//                start = tempStart;
//                end = i;
//            }
//        }
//
//        // 输出范围：nums[start..end] 即为最大子数组
//        cout << "最大子数组范围: [" << start << ", " << end << "]" << endl;
//        return maxSum;
//    }
//};//记录最大子数组范围的版本
