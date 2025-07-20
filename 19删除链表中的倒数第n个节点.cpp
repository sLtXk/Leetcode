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
//        if (!head->next)  return nullptr;//只有一个节点直接返回空节点
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
//};//自己写的两次遍历
//
//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        ListNode* dummy = new ListNode(0);  // 虚拟头结点，处理删除头结点的情况
//        dummy->next = head;
//        ListNode* fast = dummy;
//        ListNode* slow = dummy;
//        // 1. 让 fast 先走 n+1 步，这样 slow 最终停在倒数第 n+1 个节点
//        for (int i = 0; i <= n; i++) {
//            fast = fast->next;
//        }
//        // 2. 快慢指针同时移动，直到 fast 走到 nullptr
//        while (fast) {
//            fast = fast->next;
//            slow = slow->next;
//        }
//        // 3. 删除 slow->next 指向的倒数第 n 个节点
//        slow->next = slow->next->next;
//        return dummy->next;  // 返回真正的头结点
//    }
//};//更好的快慢指针