//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int n = prices.size();
//        vector<int>dpbuy(2, 0);
//        vector<int>dpnull(2, 0);
//        vector<int>frozen(2, 0);
//        dpbuy[0] = -prices[0], dpnull[0] = 0, frozen[0] = 0;
//        for (int i = 1; i < n; ++i)
//        {
//            dpnull[1] = max(dpnull[0], frozen[0]);//�����й�Ʊֻ����ǰһ��Ͳ����л������䶳��
//            dpbuy[1] = max(dpbuy[0], dpnull[0] - prices[i]);//����ֻ����֮ǰ�ͳ��л��߽������
//            frozen[1] = dpbuy[0] + prices[i];  //�䶳��ֻ����ǰһ����н�������
//            dpbuy[0] = dpbuy[1];
//            dpnull[0] = dpnull[1];
//            frozen[0] = frozen[1];
//        }
//        return max(frozen[1], dpnull[1]);//���ֵ�϶������ܳ��й�Ʊ
//    }
//};