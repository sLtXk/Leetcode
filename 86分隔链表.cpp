//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//    ListNode* partition(ListNode* head, int x) {
//        ListNode* list1 = new ListNode(0);//С�ڷָ���Ĳ���
//        ListNode* temp1 = list1;
//        ListNode* list2 = new ListNode(0);//���ڵ��ڷָ���Ĳ���
//        ListNode* temp2 = list2;
//        ListNode* curr = head;
//        while (curr)
//        {
//            if (curr->val < x)
//            {
//                temp1->next = new ListNode(curr->val);
//                temp1 = temp1->next;
//            }
//            else
//            {
//                temp2->next = new ListNode(curr->val);
//                temp2 = temp2->next;
//            }
//            curr = curr->next;
//        }
//        temp1->next = list2->next;//������������
//        return list1->next;
//    }
//};//�Լ�д�ģ��ڴ���ֽϲ�
//
//
//class Solution {
//public:
//    ListNode* partition(ListNode* head, int x) {
//        ListNode list1(0), list2(0); // ֱ��ʹ��ջ�ϵĶ��󣬱��� `new` 
//        ListNode* temp1 = &list1;
//        ListNode* temp2 = &list2;
//        ListNode* curr = head;
//
//        while (curr) {
//            if (curr->val < x) {
//                temp1->next = curr;
//                temp1 = temp1->next;
//            }
//            else {
//                temp2->next = curr;
//                temp2 = temp2->next;
//            }
//            curr = curr->next;
//        }
//
//        temp2->next = nullptr;  // �ؼ�����֤ list2 ��β����ȷ�ÿգ���������������list1��Ԫ�ص��³ɻ�����Ԫ�ز���
//        temp1->next = list2.next; // ������������
//
//        return list1.next; // ���غϲ��������
//    }
//};
