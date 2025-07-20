//#include<unordered_map>
//#include<list>
//#include<iostream>
//using namespace std;
//
//class LRUCache {
//private:
//    struct Node{
//        int key, value;
//        Node* prev;
//        Node* next;
//        Node(int k, int v) :key(k), value(v), prev(nullptr), next(nullptr) {}
//    };//˫��������ƽڵ��Ŀ����Ϊ���ܹ��洢��ֵ�Բ�����������
//    unordered_map<int,Node*>cache;//ΪʲôҪ��ô��ƣ���Ϊ��������O(1)ʱ��ͨ�����ҵ���Ӧ�Ľڵ�
//    int capacity;
//    Node* head;
//    Node* tail;//ͷ��β��㣬�¼���ļ���������ͷ
//
//    void addToHead(Node* node)
//    {
//        node->next = head->next;
//        head->next->prev = node;
//        node->prev = head;
//        head->next = node;
//    }//���ڵ�ӵ�ͷ������������¼�ֵ��
//    void removeNode(Node* node)
//    {
//        node->prev->next = node->next;
//        node->next->prev = node->prev;
//    }//����ɾ��һ���ڵ㣬�������ֱ�ӷ��ʵ�ԭ���ǹ�ϣ���д��˽ڵ�
//    void moveToHead(Node*node)
//    {
//        removeNode(node);
//        addToHead(node);
//    }//�ƶ���ͷ�������ڽ��Ѵ��ڼ�ֵ�Ը���������ͷ��
//    void removeTail()
//    {
//        Node* node = tail->prev;
//        removeNode(node);
//        delete node;
//    }//���ڽ��¾ɼ�ֵ��ɾ��
//
//public:
//    LRUCache(int capacity) :capacity(capacity){
//        head = new Node(0, 0);
//        tail = new Node(0, 0);
//        head->next = tail;
//        tail->prev = head;
//    }//�������ĳ�ʼ��
//
//    int get(int key) 
//    {
//        if (cache.find(key)!=cache.end())//����ü�ֵ���Ѵ���
//        {
//            Node* node = cache[key];//�ҵ���Ӧ�ڵ�
//            moveToHead(node);
//            return node->value;//������ֵ
//        }
//        return -1;
//    }
//    /*����,Ϊʲônode��һ����ʱָ������޸�����ṹ����Ϊ����ֻ������node������������ʵ�ڵ��ǰ��ڵ㣬
//    �������������ʵ�ڵ�,�����ʵ�ڵ㱾�����ڣ����ҿ��Ա����뵽���������λ��*/
//    void put(int key, int value) 
//    {
//        if (cache.find(key) != cache.end())//����ü�ֵ���Ѵ���
//        {
//            Node* node = cache[key];
//            node->value = value;
//            moveToHead(node);//����������ͷ
//        }
//        else
//        {
//            Node* node = new Node(key, value);//�����ü�ֵ�Զ�Ӧ�Ľڵ�
//            cache[key] = node;//��������ڵ��ӳ��
//            addToHead(node);//�ӵ�ͷ��
//            if (cache.size() > capacity)//�����������
//            {
//                Node* node = tail->prev;
//                cache.erase(node->key);//�ڹ�ϣ����Ĩ����β�ڵ��Ӧ�ļ�ֵ��
//                removeTail();//�Ƴ�����β
//            }
//        }
//    }
//}; 
//class LRUCache {
//private:
//    list<pair<int, int>>cache;//�����������Ӽ�ֵ�Բ�����ʹ�����������O(1)ͷ���β������
//    unordered_map<int, list<pair<int, int>>::iterator> map;//�������Ҽ���Ӧ�ļ�ֵ�Խڵ㣬�����������ĵ�����
//    int capacity;
//public:
//    LRUCache(int capacity) :capacity(capacity) {}
//
//    int get(int key) {
//        if (map.find(key) == map.end()) return -1;//û�ҵ�������ֱ�ӷ���
//        auto it = map[key];//��Ӧ��ֵ��������ĵ�����
//        int val = it->second;//��Ҫ���ص�ֵ
//        cache.erase(it);//�������иýڵ�ɾ��
//        cache.push_front({ key,val });//���µ�����ͷ
//        map[key] = cache.begin();//���¹�ϣ��
//        return val;
//    }
//
//    void put(int key, int value)
//    {
//        if (map.find(key) != map.end())
//        {
//            auto it = map[key];
//            cache.erase(it);//�Ƚ�ԭ�����м�ֵ�Ե�ɾ��
//        }
//        else if (map.size() >= capacity)//��������������͵ý����������һ����ֵ��ɾ��
//        {
//            int lastpair_key = cache.back().first;//���������һ����ֵ�Ե�ֵ
//            map.erase(lastpair_key);//�ӹ�ϣ����ɾ��
//            cache.pop_back();//��������ɾ��
//        }
//        cache.push_front({ key,value });//���¼�ֵ����ӵ�����ͷ
//        map[key] = cache.begin();//���¹�ϣ���м���Ӧ�ĵ�����
//    }
//};