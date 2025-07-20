//class Solution {
//public:
//    int candy(vector<int>& ratings) {
//        int n = ratings.size();
//        vector<int>left(n);
//        for (int i = 0; i < n; i++)
//        {
//            if (i > 0 && ratings[i] > ratings[i - 1])  left[i] = left[i - 1] + 1; //左规则：比前一个数大就在前一个基础上+1
//            else left[i] = 1; //没有前一个大就设为1
//        }
//        int right = 1, res = 0;
//        for (int i = n - 1; i >= 0; i--)
//        {
//            if (i<n - 1 && ratings[i]>ratings[i + 1]) right += 1; //右规则：比右边的数大就在右边基础上+1
//            else right = 1;
//            res += max(right, left[i]); //选择其中的最大值加到总个数中（因为要同时符合左右规则）
//        }
//        return res;
//    }
//};