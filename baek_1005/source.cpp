#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
	int m_time;
	int total_time;
	int m_number;
	//vector<Node*> childlist;
	vector<Node*> parlist;
	Node()
	{

	}
	Node(int time, int number)
	{
		m_time = time;
		m_number = number;
		total_time = 0;
	}
	~Node(){}
	/*
	void insertChild(Node* chi)
	{
		childlist.push_back(chi);
	}
	*/
	void insertParent(Node* par)
	{
		parlist.push_back(par);
	}
};

class Tree
{
public:
	Node* root;
	vector<Node*> nodelist;
	Tree()
	{
		root = NULL;
		Node* empty = new Node;
		nodelist.push_back(empty);
	}
	~Tree()
	{
		for (int i = 0; i < nodelist.size(); i++)
		{
			delete nodelist[i];
		}
	}
	void insertNode(Node* node)
	{
		nodelist.push_back(node);
	}

	Node* findNode(int idx)
	{
		return nodelist[idx];
	}
	void preorder(Node* current)
	{
		int time = current->m_time;
		int i;
		for (i = 0; i < current->parlist.size(); i++)
		{
			if (time + current->total_time > current->parlist[i]->total_time)
			{
				current->parlist[i]->total_time = time + current->total_time;
			}
			preorder(current->parlist[i]);
		}
		if (i == 0)
		{
			root = current;
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N, K;
		cin >> N >> K;
		
		//Tree tree;
		vector<vector<int>> graph(N + 1);
		vector<int> indegree(N + 1, 0);
		vector<int> time_to_build(N + 1, 0);
		vector<int> accumulate(N + 1, 0);
		int answer = -1;


		for (int i = 1; i <= N; i++)
		{
			// �ǹ� �Ǽ��� �ɸ��� �ð� �Է�
			int time;
			cin >> time;

			time_to_build[i] = time;
			/*
			Node* node = new Node(time, i + 1);
			tree.insertNode(node);
			*/
		}
		for (int i = 0; i < K; i++)
		{
			// �Ǽ� ������ �̿��ؼ� �׷��� �����
			int prev, next;
			cin >> prev >> next;
			graph[prev].push_back(next);
			indegree[next]++;

			/*
			//tree.findNode(prev)->insertChild(tree.findNode(next));
			tree.findNode(next)->insertParent(tree.findNode(prev));
			*/
		}
		int destination;
		cin >> destination;

		queue<int> q;
		for (int i = 1; i <= N; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}
		while (!q.empty())
		{
			int tmp = q.front(); q.pop();

			for (int num : graph[tmp])
			{
				indegree[num]--;
				accumulate[num] = max(accumulate[num], time_to_build[tmp] + accumulate[tmp]);
				if (indegree[num] == 0)
				{
					if (num == destination)
					{
						answer = time_to_build[destination] + accumulate[destination];
					}
					q.push(num);
				}

			}
			if (answer != -1)
				break;
		}
		if(answer==-1)
			answer= answer = time_to_build[destination] + accumulate[destination];
		cout << answer << endl;

		/*
		tree.preorder(tree.findNode(dest));
		cout << tree.root -> m_time + tree.root -> total_time << endl;
		*/
	}
}