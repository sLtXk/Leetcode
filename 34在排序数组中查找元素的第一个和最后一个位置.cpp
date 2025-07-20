//#include<unordered_map>
//#include<list>
//#include<iostream>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        if (nums.size() == 0) return{ -1,-1 };
//        int n = nums.size();
//        int left = 0, right = n - 1;
//        int pos = -1;
//        while (left <= right)
//        {
//            int mid = left + (right - left) / 2;
//            if (target == nums[mid])
//            {
//                pos = mid;
//                break;
//            }
//            else if (target > nums[mid]) left = mid + 1;
//            else right = mid - 1;
//        }
//        int start = pos - 1, end = pos + 1;
//        while (start >= 0 && nums[start] == target)
//            start--;
//        while (end < n && nums[end] == target)
//            end++;
//        return { start + 1,end - 1 };
//    }
//};
//
//int main()
//{
//    vector<int>nums = { 5,7,7,8,8,10 };
//    Solution a;
//    a.searchRange(nums, 8);
//}