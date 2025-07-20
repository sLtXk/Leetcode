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
//    };//双向链表，设计节点的目的是为了能够存储键值对并用链表连接
//    unordered_map<int,Node*>cache;//为什么要这么设计？因为这样可以O(1)时间通过键找到对应的节点
//    int capacity;
//    Node* head;
//    Node* tail;//头和尾结点，新加入的键放至链表开头
//
//    void addToHead(Node* node)
//    {
//        node->next = head->next;
//        head->next->prev = node;
//        node->prev = head;
//        head->next = node;
//    }//将节点加到头部，用于添加新键值对
//    void removeNode(Node* node)
//    {
//        node->prev->next = node->next;
//        node->next->prev = node->prev;
//    }//用于删除一个节点，这里可以直接访问的原因是哈希表中存了节点
//    void moveToHead(Node*node)
//    {
//        removeNode(node);
//        addToHead(node);
//    }//移动至头部，用于将已存在键值对更新至链表头部
//    void removeTail()
//    {
//        Node* node = tail->prev;
//        removeNode(node);
//        delete node;
//    }//用于将陈旧键值对删除
//
//public:
//    LRUCache(int capacity) :capacity(capacity){
//        head = new Node(0, 0);
//        tail = new Node(0, 0);
//        head->next = tail;
//        tail->prev = head;
//    }//完成链表的初始化
//
//    int get(int key) 
//    {
//        if (cache.find(key)!=cache.end())//如果该键值对已存在
//        {
//            Node* node = cache[key];//找到对应节点
//            moveToHead(node);
//            return node->value;//返回其值
//        }
//        return -1;
//    }
//    /*更新,为什么node是一个临时指针而能修改链表结构？因为我们只是利用node访问链表中真实节点的前后节点，
//    让其跳过这个真实节点,这个真实节点本身还存在，并且可以被插入到链表的其他位置*/
//    void put(int key, int value) 
//    {
//        if (cache.find(key) != cache.end())//如果该键值对已存在
//        {
//            Node* node = cache[key];
//            node->value = value;
//            moveToHead(node);//更新至链表头
//        }
//        else
//        {
//            Node* node = new Node(key, value);//创建该键值对对应的节点
//            cache[key] = node;//建立键与节点的映射
//            addToHead(node);//加到头部
//            if (cache.size() > capacity)//如果超出缓存
//            {
//                Node* node = tail->prev;
//                cache.erase(node->key);//在哈希表中抹除与尾节点对应的键值对
//                removeTail();//移除链表尾
//            }
//        }
//    }
//}; 
//class LRUCache {
//private:
//    list<pair<int, int>>cache;//链表用来连接键值对并更新使用情况，方便O(1)头插和尾部弹出
//    unordered_map<int, list<pair<int, int>>::iterator> map;//用来查找键对应的键值对节点，这里得用链表的迭代器
//    int capacity;
//public:
//    LRUCache(int capacity) :capacity(capacity) {}
//
//    int get(int key) {
//        if (map.find(key) == map.end()) return -1;//没找到迭代器直接返回
//        auto it = map[key];//对应键值对在链表的迭代器
//        int val = it->second;//需要返回的值
//        cache.erase(it);//将链表中该节点删除
//        cache.push_front({ key,val });//更新到链表头
//        map[key] = cache.begin();//更新哈希表
//        return val;
//    }
//
//    void put(int key, int value)
//    {
//        if (map.find(key) != map.end())
//        {
//            auto it = map[key];
//            cache.erase(it);//先将原链表中键值对的删除
//        }
//        else if (map.size() >= capacity)//如果超过了容量就得将链表中最后一个键值对删除
//        {
//            int lastpair_key = cache.back().first;//链表中最后一个键值对的值
//            map.erase(lastpair_key);//从哈希表中删除
//            cache.pop_back();//从链表中删除
//        }
//        cache.push_front({ key,value });//将新键值对添加到链表头
//        map[key] = cache.begin();//更新哈希表中键对应的迭代器
//    }
//};