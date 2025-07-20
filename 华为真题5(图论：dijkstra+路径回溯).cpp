///*
//��֪A����Ӫ��N��������·�������ڳ�������ʱ������·ͨƱ2Ԫ������һ�μ�1Ԫ������N����·������վ���б�
//���˿�Ѱ�Ҵӳ���վ��Ŀ��վ����˵ĵ������˷����������Ʊ�ۡ�ÿ��������·��������·����û����ͬվ����
//���룺
//��һ��Ϊ������·����N����Χ��[1, 1000]�� ��2�е���N+1 �У�ÿ����·���ΰ�����վ����ÿ��վ����������
//������������100��վ�����Ҳ������100�������ÿո��������ͬ��·����ͬ��վ������ʾ��һ������վ��
//��N+2�У�����վ��Ŀ��վ���ÿո������
//�����
//��һ�а��ճ���վ-����վ(�����Ƕ��)-Ŀ��վ�ĸ�ʽ������˷������ַ����� �ڶ���������˷�������Ʊ�ۡ�
//���û���κη�����ʵ�ֳ���վ��Ŀ��վ��ֻ���һ�У�NA��
//
//������
//���룺
//3
//A B C D F
//C G H
//M I J
//A J
//����� NA
//*/
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
//	int n; cin >> n; cin.ignore(); //����cin���뻻�з��Զ�ֹͣ��������ĩβ�ո�
//	unordered_map<string, vector<string>>graph;//ͼ,��ʾվ��֮���������ϵ
//	unordered_map<string, vector<int>>station_to_line;//ÿ��վ�������ļ�����·������ʶ�𻻳�վ��
//	vector<vector<string>>lines(n);//��¼������������Щվ��
//	for (int i = 0; i < n; i++) {
//		string temp;
//		getline(cin, temp);//����һ�е�վ����Ϣ,����cin����ո��Զ�ֹͣ����Ҫ��������
//		string station;
//		stringstream ss(temp);
//		while (getline(ss, station, ' ')) {
//			lines[i].push_back(station);//��i�д����i����·
//			station_to_line[station].push_back(i);//��¼վ��Ӧ��·��ӳ�䣬����·��������վ
//		}//����һ����·�ļ�¼
//		for (int j = 0; j < lines[i].size() - 1; j++) {
//			string a = lines[i][j];
//			string b = lines[i][j + 1];//���ڵ�����վ��
//			graph[a].push_back(b);
//			graph[b].push_back(a);//�����໥����
//		}
//	}
//
//    string start, end;
//    cin >> start >> end;
//
//    if (start == end) {
//        cout << start << endl;
//        cout << 2 << endl;
//        return 0;
//    }
//
//    struct State {
//        string station;
//        int line;
//        int cost;
//        vector<string> path;
//        bool operator>(const State& other) const {
//            return cost > other.cost;
//        }
//    };
//
//    priority_queue<State, vector<State>, greater<State>> pq;
//    set<pair<string, int>> visited; // visited[վ��][��·]����ֹ�ظ���
//
//    // �����Դ������ڵ�������·��ʼ����
//    for (int line : station_to_line[start]) {
//        pq.push({ start, line, 2, {start} });//�б��ʼ���ķ�ʽֱ�ӹ���һ����ʱ��
//        visited.insert({ start, line });
//    }
//
//    while (!pq.empty()) {
//        State cur = pq.top(); pq.pop();
//        string station = cur.station;
//        int line = cur.line;
//
//        for (const string& neighbor : graph[station]) {
//            for (int nextLine : station_to_line[neighbor]) {
//                int newCost = cur.cost;
//                if (nextLine != line) newCost++; // ���ˣ��� 1 Ԫ
//
//                if (visited.count({ neighbor, nextLine })) continue;//����ýڵ����·�Ѿ����ʹ��˾�����
//                visited.insert({ neighbor, nextLine });
//
//                vector<string> newPath = cur.path;
//                newPath.push_back(neighbor);
//
//                if (neighbor == end) {
//                    // ���·��
//                    string res = start;//���������
//                    for (int i = 0; i < newPath.size() - 1; ++i) {//�յ㵥������
//                        const string& s = newPath[i];
//                        if (station_to_line[s].size() > 1) {//����ֻѡȡ����վ���������·��Ȼ������������
//                            res += "-" + s;
//                        }
//                    }
//                    res += "-" + end;//�����յ�
//                    cout << res << endl;
//                    cout << newCost << endl;
//                    return 0;
//                }
//
//                pq.push({ neighbor, nextLine, newCost, newPath });
//            }
//        }
//    }
//	cout << "NA" << endl;//��ʱ˵������������ͨ�Ĳ�����û�ܵ����յ㣬˵��û�з������Ե������NA
//	return 0;
//}
///*
// dijkstra�㷨��������Ȩͼ�������������£�
// 1.�趨һ�������㣬�������㵽�����ĳ�ʼ������Ϊ������ӳ����㿪ʼ����
// 2.������ǰ�ڵ���ھӽڵ㣬���³����㵽�ýڵ����СȨ�أ������������С���С�
// 3.ѡ����С�ѶѶ����������ھӽڵ���Ȩ����С����һ�����ظ�����2��
// 4.��������ȡ��������Ŀ�꣬����Ϊ����ĳ���ڵ����СȨ�ػ��߱���������ͼ
//
// dijkstra�����Ͼ��Ǵ�Ȩ�صĹ��������������BFS������ʹ���ڽӱ������η��ʽڵ�ĸ����ھӣ���queue��ʵ��
// "���"�ı�������dijkstra�У�����ʹ�õ���priority_queue��ʵ�ִ�Ȩ�صı��������������Ȩ�ؾ������ǵ�cost��
// ֻ�л���cost�Ż����ӣ�������cost�ͻ���٣����ǵ�Ŀ�����ҵ�һ����Ŀ��վ��cost��С��·���������ظ�·���е�
// ��㣬�յ�ͻ��˵㣬����󷵻���С���ѣ���˿�����ȷ���ǵ�˼·���£�
// 1.�Ƚ���ͼ������¼����վ���Ӧ����·�Լ�ÿ����·��������Щվ�㣻
// 2.��������жϣ�����յ�������ֱͬ�ӷ���
// 3.��dijkstra���б�����Ѱ�ҵ��յ㻨����С��·�������������Ҫ������С�ѣ�ͬʱ���ǻ�Ҫ��¼���Ѻͻ��˵��Լ���·��
// ����������Ҫ��һ������ȷ�������Ϣ����ǰվ�㣬��ǰ������·����ǰ���ѣ��Լ���ǰ�߹���վ�㣨��������·��������
// �ø���Ԫ����Ϊ��С���д������Ϣ����С��ͨ���Ƚ�����·�ߵĵ�ǰ�����������ȱ�������·��
// 4.�����Ϊ��С���ʼ��Ԫ�أ�����㿪ʼ���������ھӽڵ㼰�ھӽڵ����ڵ���·��ͬʱ��<վ��������·>�Ĺ�ϣ������
// ��������Ѿ����ʹ���·�߸��ݵ�ǰ��·���ھӽڵ����·���ж��Ƿ�Ϊ���˵�����仨�ѣ��ټ��뵽��С���н�����һ��������
// ��һ������ѡ��Ѷ���������С�Ľڵ㡣
// 5.�ظ��˹���ֱ���ҵ��յ㣬���߱�������һ����ͨ������û���ҵ��յ㣬����������
// */