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
//        while (curr)//��ԭ����ÿ���ڵ�󴴽��ýڵ㸴��Ʒ���ȴ����ڵ������ӣ���1-2-3��Ϊ1-1'-2-2'-3-3'            
//        {
//            Node* copy = new Node(curr->val);
//            copy->next = curr->next;
//            curr->next = copy;//���ƵĽڵ����ԭ�������ڵ�֮��
//            curr = curr->next->next;//ԭ��������ԭ�������һ�ڵ�
//        }
//        //����random�ڵ�
//        curr = head;
//        while (curr)
//        {
//            if (curr->random) curr->next->random = curr->random->next;
//            curr = curr->next->next;
//        }//���ڸ��ƽڵ�Ϊԭ�ڵ����һ�ڵ㣬��ô���ƽڵ��randomָ��ľ���ԭ�ڵ��random����һ�ڵ㣬��curr->random->next
//        
//         //������������
//        Node* newhead = new Node(0);
//        Node* temp = newhead;//��������ı����ڵ�
//        curr = head;//ԭ����ı����ڵ�
//        while (curr)
//        {
//            temp->next = curr->next;//���Ƶ�����Ϊԭ�������һ���ڵ�
//            curr->next = curr->next->next;//��ԭ������һ���ڵ㻹ԭ
//            curr = curr->next;
//            temp = temp->next;//�ƶ����������ԭ����ı����ڵ�
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
//        while (curr)//��ԭ����ÿ���ڵ�󴴽��ýڵ㸴��Ʒ���ȴ����ڵ������ӣ���1-2-3��Ϊ1-1'-2-2'-3-3'            
//        {
//            Node* copy = new Node(curr->val);
//            copy->next = curr->next;
//            curr->next = copy;//���ƵĽڵ����ԭ�������ڵ�֮��
//            curr = curr->next->next;//ԭ��������ԭ�������һ�ڵ�
//        }
//        //����random�ڵ�
//        curr = head;
//        while (curr)
//        {
//            if (curr->random) curr->next->random = curr->random->next;
//            curr = curr->next->next;
//        }//���ڸ��ƽڵ�Ϊԭ�ڵ����һ�ڵ㣬��ô���ƽڵ��randomָ��ľ���ԭ�ڵ��random����һ�ڵ㣬��curr->random->next
//
//         //������������
//        Node* newhead = new Node(0);
//        Node* temp = newhead;//��������ı����ڵ�
//        curr = head;//ԭ����ı����ڵ�
//        while (curr)
//        {
//            temp->next = curr->next;//���Ƶ�����Ϊԭ�������һ���ڵ�
//            curr->next = curr->next->next;//��ԭ������һ���ڵ㻹ԭ
//            curr = curr->next;
//            temp = temp->next;//�ƶ����������ԭ����ı����ڵ�
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
//        }//�����½ڵ��ԭ�ڵ�Ĺ�ϣ��
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