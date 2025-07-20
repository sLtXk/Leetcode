//struct ListNode {
//      int val;
//     ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
//
//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int left, int right)
//    {
//        if (!head || left == right) return head;
//        int nodenum = 0;
//        ListNode* node = head;
//        ListNode* prev = nullptr;
//        ListNode* nright, * afterright;//���right��right�ĺ�һ���ڵ�
//        while (node)
//        {
//            nodenum++;
//            if (nodenum <= right && nodenum > left)
//            {
//                if (nodenum == right)
//                {
//                    nright = node;
//                    afterright = node->next;
//                }//��������Ҷ����¼��ԭ������һ���ڵ㣬��ֹ��ʧ
//                ListNode* temp = node->next;
//                node->next = prev;
//                prev = node;
//                node = temp;
//            }//��תleft��right֮�������
//            else
//            {
//                prev = node;
//                node = node->next;
//            }
//        }
//        node = head;
//        nodenum = 0;
//        while (node)
//        {
//            ++nodenum;
//            if (left == 1 && nodenum == 1)
//            {
//                node->next = afterright;
//                return nright;//���left��1������ͷ���ܵ�ĩβ����ʱӦ�÷���������ͷnright
//            }
//            if (nodenum == left - 1) node->next = nright;//leftǰһ�ڵ�ָ��right
//            else if (nodenum == right)
//            {
//                node->next = afterright;
//                break;
//            }
//            node = node->next;
//        }
//        return head;//���������������ͷ��
//    }
//};//�Լ�д��
//
//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int left, int right) {
//        if (!head || left == right) return head;
//
//        // ����αͷ�ڵ㣬���� left = 1 �����
//        ListNode* dummy = new ListNode(0);
//        dummy->next = head;
//        ListNode* pre = dummy;
//
//        // 1. �� pre ָ�� left ��ǰһ���ڵ� (left-1)
//        for (int i = 1; i < left; i++) {
//            pre = pre->next;
//        }
//
//        // 2. ��ת left �� right ֮�������
//        ListNode* cur = pre->next;
//        ListNode* next = nullptr;
//        ListNode* prev = nullptr;
//        for (int i = left; i <= right; i++) {
//            next = cur->next;
//            cur->next = prev;
//            prev = cur;
//            cur = next;
//        }//������pre��right��λ�ã�cur��next����ԭright+1��λ��
//
//        // 3. ���ӷ�ת������ʣ�ಿ��
//        pre->next->next = cur;  // pre->next��ʵ����ԭ����left,left��left-1��next����ָ��Է�����ʱֻ�轫ԭ����ͷ���ӵ�cur��λ�ü���
//        pre->next = prev;       // pre����һ���ڵ�ָ��ԭ����β����ɷ�ת
//
//        return dummy->next;  // αͷ�ڵ�� next �����µ�ͷ
//    }
//};//gpt�Ż���