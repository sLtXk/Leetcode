//class Solution {
//public:
//    int candy(vector<int>& ratings) {
//        int n = ratings.size();
//        vector<int>left(n);
//        for (int i = 0; i < n; i++)
//        {
//            if (i > 0 && ratings[i] > ratings[i - 1])  left[i] = left[i - 1] + 1; //����򣺱�ǰһ���������ǰһ��������+1
//            else left[i] = 1; //û��ǰһ�������Ϊ1
//        }
//        int right = 1, res = 0;
//        for (int i = n - 1; i >= 0; i--)
//        {
//            if (i<n - 1 && ratings[i]>ratings[i + 1]) right += 1; //�ҹ��򣺱��ұߵ���������ұ߻�����+1
//            else right = 1;
//            res += max(right, left[i]); //ѡ�����е����ֵ�ӵ��ܸ����У���ΪҪͬʱ�������ҹ���
//        }
//        return res;
//    }
//};