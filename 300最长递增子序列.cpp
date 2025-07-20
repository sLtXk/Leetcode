//#include<iostream>
//#include<vector>
//#include<deque>
//#include<unordered_set>
//#include<list>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        if (nums.size() == 0) return 0;
//        int n = nums.size();
//        vector<int>dp(n, 1);//记录第i个元素下最长递增子序列的长度
//        dp[0] = 0;//第0个元素没有子序列，长度为0
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < i; j++)//遍历当前元素的所有子序列
//            {
//                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);//只有当前元素比第j个元素大，才有可能组成更长的子序列
//            }
//        }
//    }
//};//DP,时间复杂度O(n^2)
//
//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        if (nums.size() == 0) return 0;
//        int n = nums.size();
//        vector<int>sub(n,0);//维护一个严格递增序列
//        int j = 0;//用于标记递增序列的最大元素位置
//        sub[j] = nums[0];
//        for (int i = 0; i < n; i++)
//        {
//            if (nums[i] > sub[j]) sub[++j] = nums[i];//如果当前元素比递增序列的最大值还大,添加至递增序列末尾
//            else
//            {
//                int left = 0, right = j;
//                while (left <= right)//nums[i]是我们需要寻找的数
//                {
//                    int mid = left + (right - left) / 2;
//                    if (sub[mid]>=nums[i]) right = mid - 1;//如果 nums[i] == sub[mid]，说明 mid 可能是符合要求的位置，但为了找到最左边的一个，我们需要继续缩小右边界，向左搜索。
//                    else left = mid + 1;
//                }//在维护的递增序列中替换第一个大于等于nums[i]的数（等于也要换是因为严格递增），如果是找第一个大于nums[i]的位置的，就用sub[mid]>nums[i]
//                sub[left] = nums[i];
//            }
//            /*为什么left是正确位置：如果nums[i]大于序列中所有数，则left会加到j+1的位置，符合nums[i]添加至末尾的情况;
//            如果nums[i]小于序列中所有数，则应该取代序列中第一个数，对应到循环最后left=0不变而right=-1的情况*/
//        }
//        return j;
//    }
//};