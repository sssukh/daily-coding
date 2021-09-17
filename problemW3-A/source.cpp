#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;


class Node {
public:
	Node* parrent;
	vector<Node*> chilist;
	int value;
	
	Node()
	{
		parrent = NULL;
		value = 0;
	}
	~Node() {};
	
	
};

class Tree {
public:
	
	vector<Node*> nodelist;
	Tree(){ }
	Tree(int n)
	{
		while (n--)
			nodelist.push_back(new Node);
	}
	~Tree() {};
	
	
	void insertNode(int parent_idx, int idx)
	{
		Node* par = nodelist[parent_idx-1];
		Node* chi = nodelist[idx-1];
		chi->parrent = par;
		par->chilist.push_back(chi);
	}

	void preorder(Node* node)
	{
		
		for (Node* cur : node->chilist)
		{
			cur->value += cur->parrent->value+1;
			preorder(cur);
		}
	}

	int totallen(Node* node)
	{
		Node* current = node;
		int total = 0;
		while (current != NULL)
		{
			total += current->value;
			total++;
			current = current->parrent;
		}
		return total-1;
	}
	
};

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		Tree* direc = new Tree(N);
		
		
		for (int i = 0; i < N-1; i++)
		{
			int a, b;
			cin >> a >> b;
			direc->insertNode(a, b);
		}
		for (int i = 0; i < N; i++)
		{
			string a;
			cin >> a;
			direc->nodelist[i]->value = a.size();
		}

		direc->preorder(direc->nodelist[0]);
		for (Node* n : direc->nodelist)
		{
			cout <<n->value << endl;
		}
		delete direc;
	}
}


/*
int sumtotal(int ,vector<int>&,vector<int>& );



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		
		vector<int> par(N+1,0);
		vector<int> val(N+1,0);
		for (int i = 0; i < N-1; i++)
		{
			int a, b;
			cin >> a >> b;
			par[b] = a;
		}

		for (int i = 0; i < N; i++)
		{
			string a;
			cin >> a;
		
			val[i + 1] = a.length();
		}

		for (int i = 1; i <= N; i++)
		{
			cout << sumtotal(i, par, val) <<"\n";
		
		}
	}
}

int sumtotal(int idx,vector<int>& par,vector<int>& val)
{
	if (idx==0)
		return -1;
	return val[idx] + sumtotal(par[idx],  par,  val)+1;
}
*/