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
//        vector<int>dp(n, 1);//��¼��i��Ԫ��������������еĳ���
//        dp[0] = 0;//��0��Ԫ��û�������У�����Ϊ0
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 0; j < i; j++)//������ǰԪ�ص�����������
//            {
//                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);//ֻ�е�ǰԪ�رȵ�j��Ԫ�ش󣬲��п�����ɸ�����������
//            }
//        }
//    }
//};//DP,ʱ�临�Ӷ�O(n^2)
//
//class Solution {
//public:
//    int lengthOfLIS(vector<int>& nums) {
//        if (nums.size() == 0) return 0;
//        int n = nums.size();
//        vector<int>sub(n,0);//ά��һ���ϸ��������
//        int j = 0;//���ڱ�ǵ������е����Ԫ��λ��
//        sub[j] = nums[0];
//        for (int i = 0; i < n; i++)
//        {
//            if (nums[i] > sub[j]) sub[++j] = nums[i];//�����ǰԪ�رȵ������е����ֵ����,�������������ĩβ
//            else
//            {
//                int left = 0, right = j;
//                while (left <= right)//nums[i]��������ҪѰ�ҵ���
//                {
//                    int mid = left + (right - left) / 2;
//                    if (sub[mid]>=nums[i]) right = mid - 1;//��� nums[i] == sub[mid]��˵�� mid �����Ƿ���Ҫ���λ�ã���Ϊ���ҵ�����ߵ�һ����������Ҫ������С�ұ߽磬����������
//                    else left = mid + 1;
//                }//��ά���ĵ����������滻��һ�����ڵ���nums[i]����������ҲҪ������Ϊ�ϸ��������������ҵ�һ������nums[i]��λ�õģ�����sub[mid]>nums[i]
//                sub[left] = nums[i];
//            }
//            /*Ϊʲôleft����ȷλ�ã����nums[i]��������������������left��ӵ�j+1��λ�ã�����nums[i]�����ĩβ�����;
//            ���nums[i]С������������������Ӧ��ȡ�������е�һ��������Ӧ��ѭ�����left=0�����right=-1�����*/
//        }
//        return j;
//    }
//};