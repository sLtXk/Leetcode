//#include<iostream>
//#include<unordered_map>
//using namespace std;
//// Definition for a Node.
//class Node {
//public:
//    int val;
//    Node* next;
//    Node* random;
//
//    Node(int _val) {
//        val = _val;
//        next = NULL;
//        random = NULL;
//    }
//};
//
//
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        if(!head) return nullptr;
//        Node* curr = head;
//        while (curr)//在原链表每个节点后创建该节点复制品，先创建节点再连接，如1-2-3变为1-1'-2-2'-3-3'            
//        {
//            Node* copy = new Node(curr->val);
//            copy->next = curr->next;
//            curr->next = copy;//复制的节点插在原链表两节点之间
//            curr = curr->next->next;//原链表跳到原链表的下一节点
//        }
//        //连接random节点
//        curr = head;
//        while (curr)
//        {
//            if (curr->random) curr->next->random = curr->random->next;
//            curr = curr->next->next;
//        }//由于复制节点为原节点的下一节点，那么复制节点的random指向的就是原节点的random的下一节点，即curr->random->next
//        
//         //分离两个链表
//        Node* newhead = new Node(0);
//        Node* temp = newhead;//复制链表的遍历节点
//        curr = head;//原链表的遍历节点
//        while (curr)
//        {
//            temp->next = curr->next;//复制的链表为原链表的下一个节点
//            curr->next = curr->next->next;//将原链表下一个节点还原
//            curr = curr->next;
//            temp = temp->next;//移动复制链表和原链表的遍历节点
//        }
//        return newhead->next;
//    }
//};
//
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        if (!head) return nullptr;
//        Node* curr = head;
//        while (curr)//在原链表每个节点后创建该节点复制品，先创建节点再连接，如1-2-3变为1-1'-2-2'-3-3'            
//        {
//            Node* copy = new Node(curr->val);
//            copy->next = curr->next;
//            curr->next = copy;//复制的节点插在原链表两节点之间
//            curr = curr->next->next;//原链表跳到原链表的下一节点
//        }
//        //连接random节点
//        curr = head;
//        while (curr)
//        {
//            if (curr->random) curr->next->random = curr->random->next;
//            curr = curr->next->next;
//        }//由于复制节点为原节点的下一节点，那么复制节点的random指向的就是原节点的random的下一节点，即curr->random->next
//
//         //分离两个链表
//        Node* newhead = new Node(0);
//        Node* temp = newhead;//复制链表的遍历节点
//        curr = head;//原链表的遍历节点
//        while (curr)
//        {
//            temp->next = curr->next;//复制的链表为原链表的下一个节点
//            curr->next = curr->next->next;//将原链表下一个节点还原
//            curr = curr->next;
//            temp = temp->next;//移动复制链表和原链表的遍历节点
//        }
//        return newhead->next;
//    }
//};
//
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        if (!head) return nullptr;
//        unordered_map<Node*, Node*>map;
//        Node* curr = head;
//        while (curr)
//        {
//            map[curr] = new Node(curr->val);
//            curr = curr->next;
//        }//建立新节点和原节点的哈希表
//        curr = head;
//        while (curr)
//        {
//            map[curr]->next = map[curr->next];
//            map[curr]->random = map[curr->random];
//            curr = curr->next;
//        }
//        return map[head];
//    }
//};