//#include <iostream>
//#include <string>
//#include <vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int n = nums.size();
//        vector<int>sum(n + 1, 0);//记录前缀和，sum[n]记录nums前n个元素,sum[0]就由于没有元素所以是0
//        for (int i = 1; i <= n; i++)
//        {
//            sum[i] = sum[i - 1] + nums[i - 1];
//        }
//        int ans = n + 1;
//        for (int i = 0; i < n; i++)//i不可能为n，因为sum[n]已经是所有数的前缀和了，找不到sumj比sumn还大
//        {
//            int sumj = target + sum[i];
//            auto it = lower_bound(sum.begin(), sum.end(), sumj); //二分查找，找到大于等于sumj的第一个索引 
//            if (it != sum.end())
//            {
//                ans = min(ans, int(it - nums.begin()) - i);//选择较小的长度
//            }
//        }
//        return ans == n + 1 ? 0 : ans;
//    }
//    /*sum[j]-sum[i]>=target就满足目标子数组条件，sum[j]对应nums[0:j-1]的和，sum[i]对应nums[0:i-1]的和
//    两者相减得到区间i:j-1的和，区间长度就为j-i,所以我们只需要找到一个sumj大于target+sum[i]即可*/
//};//前缀法+二分查找
//
//
//class Solution2{
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int n = nums.size();
//        int start = 0, end = 0,ans=n+1;
//        int sum = 0;
//        while (end < n)
//        {
//            sum += nums[end];
//            while (sum >= target)//如果当前窗口比目标值大，就可以从左边减小窗口，直到窗口小于目标值
//            {
//                ans = min(ans, end - start + 1);
//                sum -= nums[start]; 
//                start++;
//            }
//            end++;
//        }
//        return ans==n+1? 0:ans;
//    }
//};//滑动窗口
//
//int main()
//{
//    vector<int>nums{ 0,1,2,3,4 };
//    Solution a;
//    cout << a.minSubArrayLen(6, nums);
//}