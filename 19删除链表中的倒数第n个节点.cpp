//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        if (!head->next)  return nullptr;//ֻ��һ���ڵ�ֱ�ӷ��ؿսڵ�
//        ListNode* dummy = new ListNode(0);
//        dummy->next = head;
//        ListNode* node = head;
//        int num = 0;
//        while (node)
//        {
//            num++;
//            node = node->next;
//        }
//        if (num == n)
//        {
//            dummy->next = dummy->next->next;
//            return dummy->next;
//        }
//        node = head;
//        for (int i = 1; i < num - n; i++)
//            node = node->next;
//        node->next = node->next->next;
//        return head;
//    }
//};//�Լ�д�����α���
//
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        ListNode* dummy = new ListNode(0);  // ����ͷ��㣬����ɾ��ͷ�������
//        dummy->next = head;
//        ListNode* fast = dummy;
//        ListNode* slow = dummy;
//        // 1. �� fast ���� n+1 �������� slow ����ͣ�ڵ����� n+1 ���ڵ�
//        for (int i = 0; i <= n; i++) {
//            fast = fast->next;
//        }
//        // 2. ����ָ��ͬʱ�ƶ���ֱ�� fast �ߵ� nullptr
//        while (fast) {
//            fast = fast->next;
//            slow = slow->next;
//        }
//        // 3. ɾ�� slow->next ָ��ĵ����� n ���ڵ�
//        slow->next = slow->next->next;
//        return dummy->next;  // ����������ͷ���
//    }
//};//���õĿ���ָ��