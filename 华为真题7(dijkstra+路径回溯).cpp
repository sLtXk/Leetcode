///*
//������ĳ���е�����·�ǳ��ܼ����˿ͺ���һ�ۿ���ѡ��������·�����ȽϺ��ʣ�Ϊ�˽��������⣬
//������˾ϣ���㿪��һ����������˿���ѡ���ʵĳ�����·��ʹ�ó���ʱ����̣�������˾�����ṩ
//�������Ǹ�����վ��֮��ĳ���ʱ�䡣
//���룺
//��һ��:N��վ������,3<=N<=20.
//�ڶ���:�˿� �ĳ����͵���վ�㡣
//��������:����վ��֮��ĳ���ʱ�䣬ÿ��վ��һ�У�վ�������ǵ���Сд��ĸ��վ����һ�����������͵���վ�㣬���뱣ֻ֤��һ��Ψһ��;
//������:0000
//
//�����
//��ʱ��̵���·
//ʾ����
//���룺
//12
//a e
//a b 2
//b c 2
//c d 2
//d e 2
//f b 3
//b g 3
//g h 2
//h i 3
//j h 2
//h e 3
//e k 2
//k i 4
//0000
//
//�����
//a b c d e
//*/
//
//
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//#include<set>
//#include<unordered_set>
//#include<string>
//#include<algorithm>
//#include<sstream>
//#include<queue>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	char start, dest;
//	cin >> start >> dest;
//	cin.ignore();
//	unordered_map<char, vector<pair<char, int>>>graph;//�ֱ���վ�㣬����վ��Ͷ�Ӧ��ʱ��
//	string line;
//	while (getline(cin, line)) {
//		if (line == "0000") break;
//		stringstream ss(line);
//		char station, neighbor;
//		int time;
//		ss >> station >> neighbor >> time;
//		graph[station].push_back({ neighbor,time });//��ͼ
//		graph[neighbor].push_back({ neighbor,time });
//	}
//
//	unordered_map<char, int>time;//��¼�����վ������ʱ��
//	unordered_map<char, char>prev;//��¼��ǰ�ڵ��ǰһ�ڵ�
//	for (auto& p : graph) {
//		time[p.first] = INT_MAX;//���ɴ�ڵ��Ϊ������
//	}
//	time[start] = 0;//���Լ���ʱ����0
//
//	priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>>pq;//����ʱ������
//	pq.push({ 0,start });
//	while (!pq.empty()) {
//		auto p = pq.top(); pq.pop();//ȡ���Ѷ����Ƕ��е���ʱ����̵Ľڵ�
//		int t = p.first;//ԭ������վ���ʱ��
//		char station = p.second;//��ǰվ��
//		if (t > time[station]) continue;//����Ѿ���ʱ����̵�·���ˣ�������·��
//		for (auto neighbor : graph[station]) {//������ǰվ����ھ�
//			char cur_neighbor = neighbor.first;
//			int cur_t = neighbor.second;
//			if (time[cur_neighbor] > time[station] + cur_t) {//���ﵱǰ�ھӴ��ڸ��̵�·��
//				time[cur_neighbor] = time[station] + cur_t;//���¸���·��
//				prev[cur_neighbor] = station;//���µ����ھ����·���е�ǰһվ��
//				pq.push({ time[cur_neighbor],cur_neighbor });//�������ȶ���
//			}
//		}
//	}
//	vector<char>path;
//	for (char ch = dest; ch != start; ch = prev[ch]) {
//		path.push_back(ch);
//	}
//	path.push_back(start);
//	for (int i = path.size() - 1; i > 0; i--) {
//		cout << path[i] << ' ';
//	}
//	cout << path[0] << endl;
//}