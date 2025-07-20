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
//        ListNode* list1 = new ListNode(0);//小于分隔点的部分
//        ListNode* temp1 = list1;
//        ListNode* list2 = new ListNode(0);//大于等于分隔点的部分
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
//        temp1->next = list2->next;//连接两个链表
//        return list1->next;
//    }
//};//自己写的，内存表现较差
//
//
//class Solution {
//public:
//    ListNode* partition(ListNode* head, int x) {
//        ListNode list1(0), list2(0); // 直接使用栈上的对象，避免 `new` 
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
//        temp2->next = nullptr;  // 关键：保证 list2 的尾部正确置空，否则后面会连接着list1的元素导致成环或者元素不对
//        temp1->next = list2.next; // 连接两个链表
//
//        return list1.next; // 返回合并后的链表
//    }
//};
