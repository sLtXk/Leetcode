//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<stack>
//using namespace std;
//
//int main() {
//	int n;cin >> n;
//	string poker;
//	for (int i = 0; i < n; i++) {
//		char ch;
//		cin>>ch;
//		poker += ch;
//	}
//	string temp;
//	int count = 1;
//	for (char& ch : poker) {
//		if (ch != ' ') {			
//			temp += ch;
//			int i = temp.size() - 1;//标记当前字符串尾部
//			if (i >= 2 && temp[i] == temp[i - 1] &&temp[i-1]== temp[i - 2]) {
//				for (int j = 0; j < 3; j++) {
//					temp.pop_back();
//				}
//			}
//		}
//	}
//	string res;
//	if (temp.size() == 0) res += '0';
//	else {
//		for (char& ch : temp) {
//			res += ch;
//			res += ' ';
//		}
//		res.pop_back();
//	}
//	for (int i = 0; i < res.size();i++) {
//		cout << res[i];
//	}
//	return  0;
//}
