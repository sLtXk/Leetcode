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
//    vector<int>num;//存储数字
//    unordered_map<int, int>map;//键为数组中的数，值为其索引
//public:
//    RandomizedSet() {
//        srand(time(0));  //只用全局初始化一次
//    }
//
//    bool insert(int val) {
//        if (map.find(val) != map.end())
//            return false;
//        map[val] = num.size();//由于是一个一个放入数组，放入的数索引为size-1
//        num.push_back(val);
//        return true;
//    }
//
//    bool remove(int val) {
//        if (map.find(val) == map.end()) return false;
//        int index = map[val], last = num.back();//由于要删除val，需要在数组中将val的值覆盖成最后一位数，然后将最后一位删除即可
//        num[index] = last;
//        map[last] = index;//由于最后一位数temp已经移到被删除的数val的位置了，所以要更新其对应的索引
//        num.pop_back();
//        map.erase(val);/*这句必须放在map[last]=index之后，因为如果要删的数
//        就在数组的最后一位，那么放在该句之前会导致map[last]的值被再次创建*/
//        return true;
//    }
//
//    int getRandom() {
//        if (num.size() == 0)  return 0;
//        int randomnum = rand() % num.size();
//        return num[randomnum];
//    }
//};
/*由于题目要求查找，删除，和返回随机数的时间都是O(1)，因此我们可以很自然的联想到哈希表的查找和删除时间是O(1)，
但是由于哈希表是红黑树构造，其访问时间复杂度是O(n)而vector是线性存储，其访问时间就是O(1)，因此我们可以查找和
删除元素时使用哈希表，而随机数返回使用vector。 */

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */