//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//class Solution {
//public:
//    ListNode* rotateRight(ListNode* head, int k) {
//        if (!head || !head->next) return head;
//        ListNode* dummy = new ListNode(0);
//        dummy->next = head;
//        int n = 1;//��¼����
//        ListNode* tail = head;//β�ڵ�
//        while (tail->next)
//        {
//            tail = tail->next;
//            n++;
//        }
//        //���ڵ��������޷��Ӻ���ǰ������������ǽ�����kλ������Ϊ��ͷ�ڵ�������βn-k�β���
//        for (int i = 1; i <= n - k % n; i++)//����k����n�����
//        {
//            tail->next = dummy->next;//��ͷ�ڵ�����β�������Ʊ�֤tail�ܸ���
//            tail = tail->next;//β����
//            dummy->next = dummy->next->next;//�����µ�ͷ���
//            tail->next = nullptr;
//        }
//        return dummy->next;
//    }
//};//�Լ�д��
//
//class Solution {
//public:
//    ListNode* rotateRight(ListNode* head, int k) {
//        if (!head || !head->next || k == 0) return head;
//        // ���������ȣ����ҵ�β�ڵ�
//        int n = 1;
//        ListNode* tail = head;
//        while (tail->next)
//        {
//            tail = tail->next;
//            n++;
//        }
//        // ���� k ��������
//        k = k % n;
//        if (k == 0) return head;
//        // �ҵ���ͷ��ǰ���ڵ� (�� n - k ���ڵ�)
//        ListNode* prev = head;
//        for (int i = 1; i < n - k; i++)
//            prev = prev->next;
//        // //����µ�ͷ��λ��
//        ListNode* newHead = prev->next;
//        prev->next = nullptr;//���µ�β�ڵ���һ�ڵ���Ϊ��
//        tail->next = head;//ֱ�ӽ�ԭ��β������ԭ����ͷ��
//        return newHead;
//    }
//};//gpt�Ż�ָ������