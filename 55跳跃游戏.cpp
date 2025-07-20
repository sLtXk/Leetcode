//class Solution {
//public:
//    bool canJump(vector<int>& nums)
//    {
//        int n = nums.size(), currpos = 0, maxpos = 0;
//        for (int i = 0; i < n; i++)
//        {
//            if (i > maxpos) return false;
//            else maxpos = max(maxpos, i + nums[i]);
//        }
//        return maxpos >= n - 1 ? 1 : 0;
//    }
//};