#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
	int key;
	int time;
	int total_time;
	vector<Node> Child;
	vector<Node> Parrent;
	Node() {
		key = NULL;
		time = NULL;
		total_time = NULL;
		
	}
	Node(int key){
		this->key = key;
		time = 0;
		total_time = 0;
		
		
	}
	void insertChild(Node child) {
		this->Child.push_back(child);
	}
	void insertParrent(Node parrent) {
		this->Parrent.push_back(parrent);
	}

	
};


int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, K, W;
		cin >> N >> K;
		vector<Node> tree;
		tree.push_back(Node());//index를 맞추기위해 넣는 empty Node
		for (int i = 1; i <= N; i++) {//Node 생성 후 time 입력받아 넣기
			tree.push_back(Node(i));
			int time;
			cin >> time;
			tree[i].time = time;
			tree[i].total_time = time;
		}
		while (K--) {
			int a, b;
			cin >> a >> b;
			tree[a].insertChild(tree[b]);
			tree[b].insertParrent(tree[a]);
		}
		/*
		for (int i = 1; i < tree.size(); i++) {
			for (int j = 0; j < tree[i].Child.size(); j++) {
				int tmp;
				if (tree[i].Child[j].total_time < tree[i].total_time + tree[i].Child[j].time) {
					tmp = tree[i].total_time + tree[i].Child[j].time;
					tree[i].Child[j].total_time = tmp;
					cout << 1 << endl;
				}
			}
		}
		*/

		
		for (Node n : tree) {
			cout << n.key << " !!! " << n.total_time << endl;
		}
		cin >> W;
		cout << tree[W].total_time<<endl;
	}
}