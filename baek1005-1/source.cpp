#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node {
public:
	int key;
	int time;
	int total_time;
	vector<Node*> Child;
	vector<Node*> Parrent;
	Node() {
		key = NULL;
		time = NULL;
		total_time = NULL;
		
	}
	Node(int key, int time){
		this->key = key;
		this->time = time;
		total_time = time;
		
		
	}
	void insertChild(Node* child) {//child에 추가
		this->Child.push_back(child);
	}
	void insertParrent(Node* parrent) {//parrent 에 추가
		this->Parrent.push_back(parrent);
	}
	void addTime() {
		for (int i = 0; i < Child.size(); i++) {
			if (Child[i]->total_time < total_time + Child[i]->time) {
				Child[i]->total_time = total_time + Child[i]->time;
			}
		}
	}
	
};

class Tree {
public:
	Node* root;
	vector<Node*> node_list;
	Tree() {
		root = NULL;
	}
	Tree(int data,int time) {
		root = new Node(data,time);
		node_list.push_back(root);
	}
	~Tree(){}
	void insertNode(int data,int time) {
		node_list.push_back(new Node(data,time));
	}
	void setRoot(Node* node) {
		root = node;
	}
	Node* findNode(int data) {
		for (int i = 0; i < node_list.size(); i++) {
			if (node_list[i]->key == data) {
				return node_list[i];
			}
		}
	}
	Node* findNodeTime(int data,Node* node) {
		Node* current = node;
		for (int i = 0; i < current->Child.size(); i++) {

		}
	}

	void preOrder(Node* node) {
		node->addTime();
		for (int i = 0; i < node->Child.size(); i++) {
			preOrder(node->Child[i]);
		}
	}
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, K, W;
		cin >> N >> K;
		Tree tree;
		for (int i = 1; i <= N; i++) {//tree초기화
			int time;
			cin >> time;
			tree.insertNode(i,time);
			
		}
		
		
		while (K--) {//자식관계 입력
			int a, b;
			cin >> a >> b;
			tree.findNode(a)->insertChild(tree.findNode(b));
			tree.findNode(b)->insertParrent(tree.findNode(a));
		}
		for (Node* n : tree.node_list) {//root 설정
			if (n->Parrent.empty()) {
				tree.setRoot(n);
				break;
			}
		}
		//cout << "root : " << tree.root->key << endl;
		//for (Node* n : tree.node_list) {
		//	n->addTime();
		//}
		tree.preOrder(tree.root);//total_time 구하기

		
		
		cin >> W;
		cout << tree.findNode(W)->total_time<<endl;
	}
}