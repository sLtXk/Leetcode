//#include<iostream>
//#include<vector>
//#include<string>
//#include<unordered_map>
//#include<cstdlib>
//#include<ctime>
//#include<random>
//#include<algorithm>
//using namespace std;
//
//class RandomizedSet {
//private:
//    vector<int>num;//�洢����
//    unordered_map<int, int>map;//��Ϊ�����е�����ֵΪ������
//public:
//    RandomizedSet() {
//        srand(time(0));  //ֻ��ȫ�ֳ�ʼ��һ��
//    }
//
//    bool insert(int val) {
//        if (map.find(val) != map.end())
//            return false;
//        map[val] = num.size();//������һ��һ���������飬�����������Ϊsize-1
//        num.push_back(val);
//        return true;
//    }
//
//    bool remove(int val) {
//        if (map.find(val) == map.end()) return false;
//        int index = map[val], last = num.back();//����Ҫɾ��val����Ҫ�������н�val��ֵ���ǳ����һλ����Ȼ�����һλɾ������
//        num[index] = last;
//        map[last] = index;//�������һλ��temp�Ѿ��Ƶ���ɾ������val��λ���ˣ�����Ҫ�������Ӧ������
//        num.pop_back();
//        map.erase(val);/*���������map[last]=index֮����Ϊ���Ҫɾ����
//        ������������һλ����ô���ڸþ�֮ǰ�ᵼ��map[last]��ֵ���ٴδ���*/
//        return true;
//    }
//
//    int getRandom() {
//        if (num.size() == 0)  return 0;
//        int randomnum = rand() % num.size();
//        return num[randomnum];
//    }
//};
/*������ĿҪ����ң�ɾ�����ͷ����������ʱ�䶼��O(1)��������ǿ��Ժ���Ȼ�����뵽��ϣ��Ĳ��Һ�ɾ��ʱ����O(1)��
�������ڹ�ϣ���Ǻ�������죬�����ʱ�临�Ӷ���O(n)��vector�����Դ洢�������ʱ�����O(1)��������ǿ��Բ��Һ�
ɾ��Ԫ��ʱʹ�ù�ϣ�������������ʹ��vector�� */

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */