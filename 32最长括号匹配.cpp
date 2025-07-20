//#include<stack>
//#include<iostream>
//using namespace std;
//
//
//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        stack<int>stk;//��¼��ջ�������ŵ��±�
//        int maxlen = 0;
//        stk.push(-1);//��ʼ��׼,��Ϊs[i]��s[j]������i-j+1��������-1��Ȼ��ʾ����
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] == '(') stk.push(i);
//            else {
//                stk.pop();//����������ž�ֱ�ӵ���
//                if (stk.empty()) stk.push(i);//�����������ջ�ǿյģ�˵���ǵ�һ�������ţ�������Ч����,��Ϊ�µĻ�׼
//                else maxlen = max(maxlen, i - stk.top());//����л�׼����󳤶ȸ���
//            }
//        }
//        //������Ч����������Ϊ��һ����Ч���ŵĻ�׼����
//        return maxlen;
//    }
//};//�ⷨ1��ջ
//
//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        int left = 0, right = 0;//��¼������������
//        int maxlen = 0;
//        for (char& ch : s) {//�����Ҽ���
//            if (ch == '(') left++;
//            else right++;
//
//            if (right > left) left = right = 0;//�����Ҽ����������ŵ����������Դ��������ţ������Ȼ��Ч����������
//            else if (left == right) maxlen = max(maxlen, left * 2);//�����������������ȣ����ȼ�Ϊ��2
//            //�����Ҽ��������ſ��Զ���������
//        }
//        left = right = 0;
//        for (int i = s.size() - 1; i >= 0; i--) {
//            if (s[i] == ')') right++;
//            else left++;
//
//            if (left > right) left = right = 0;//���ҵ�������������ŵ����������Դ��������ţ������Ȼ��Ч����������
//            else if (left == right) maxlen = max(maxlen, left * 2);//�����������������ȣ����ȼ�Ϊ��2
//            //���ҵ�����������ſ��Զ���������
//        }
//        return maxlen;
//    }
//};