//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */
//class Solution {
//public:
//    ListNode* deleteDuplicates(ListNode* head) {
//        if (!head) return head;
//        ListNode* dummy = new ListNode(0);
//        dummy->next = head;
//        ListNode* prev = dummy;
//        ListNode* curr = head;
//        ListNode* next = curr->next;
//        bool flag = 0;
//        while (next)
//        {
//            while (next && curr->val == next->val)//�ж���һ��Ԫ���Ƿ�Ϊ�ظ�Ԫ��
//            {
//                next = next->next;
//                flag = 1;
//            }
//            if (flag == 1)//������ظ�Ԫ��
//            {
//                curr = next;//curr����Ϊ�ظ����ֵ���һ��
//                prev->next = next;//�����ظ���Ԫ��,prev���ø����Ա�֤�����ظ����ֵ�ǰ��
//                flag = 0;
//                if (next) //���next�������һ���ͽ��ŵ���
//                    next = next->next;//next����Ϊ��һ���ڵ㣬֮��ص�����whileѭ�������ж�
//            }
//            else
//            {
//                prev = prev->next;
//                curr = curr->next;
//                next = next->next;//������ظ�������ͬʱ����
//            }
//        }
//        return dummy->next;
//    }
//};//�Լ�д��
//
//class Solution {
//public:
//    ListNode* deleteDuplicates(ListNode* head) {
//        if (!head) return nullptr;
//        ListNode* dummy = new ListNode(0, head);
//        ListNode* prev = dummy;
//        ListNode* curr = head;
//        while (curr)
//        {
//            // 1. �����ظ�Ԫ�أ���ǰ�����ҵ���һ����ͬ��Ԫ��
//            while (curr->next && curr->val == curr->next->val)
//                curr = curr->next;
//            // 2. ��� prev ����һ����Ȼ�� curr��˵�� curr �����ظ�Ԫ��
//            if (prev->next == curr) prev = prev->next;
//            else prev->next = curr->next;
//            curr = curr->next;
//        }
//        return dummy->next;
//    }
//};//gpt�Ż�������